/*
 * gyro2.c
 *
 *  Created on: 27 feb. 2018
 *      Author: thomas
 */

#include <mems.h>
#include "main.h"
#include "debug.h"



/***
 * init function
 */

void mems_init_transmit(uint8_t buffer_0,uint8_t buffer_1,UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	uint8_t receivebuffer_8[10];
	HAL_StatusTypeDef spi_status;
	uint8_t sendbuffer_8[2];
	sendbuffer_8[0]=buffer_0;
	sendbuffer_8[1]=buffer_1;
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 2, 5000);
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
}


void mems_init8b(UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	//reset mpu
	mems_init_transmit(PWR_MGMT_1,0x80,huart_ptr,hspi_ptr); //reset
	HAL_Delay(100); //delay after reset device
	mems_init_transmit(PWR_MGMT_1,0x01,huart_ptr,hspi_ptr);

	mems_init_transmit(GYRO_CONFIG,0x13,huart_ptr,hspi_ptr);

	mems_init_transmit(ACC_CONFIG,0x18,huart_ptr,hspi_ptr);
	mems_init_transmit(ACC_CONFIG2,0x08,huart_ptr,hspi_ptr);

	mems_init_transmit(ACC_Z_OFF_H,0x19,huart_ptr,hspi_ptr);
	mems_init_transmit(ACC_Z_OFF_L,0x54,huart_ptr,hspi_ptr);

	HAL_Delay(100); //delay after reset device
}


int16_t mems_read(uint8_t type, UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	uint8_t receivebuffer_8[10];
	HAL_StatusTypeDef spi_status;
    uint8_t sendbuffer_8[2];
    uint8_t result_h,result_l;
    int16_t return_value=0;
    sendbuffer_8[0]=type;
    sendbuffer_8[1]=0x00;

    HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 2, 5000);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);
	result_h=receivebuffer_8[1];
    sendbuffer_8[0]=type+1;
    sendbuffer_8[1]=0x00;
    HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)(sendbuffer_8), (uint8_t *)(receivebuffer_8), 2, 5000);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);
	result_l=receivebuffer_8[1];

	if(spi_status==HAL_OK){
		return_value= (int16_t)((reverse_byte(result_h)<<8) | (reverse_byte(result_l)));
	}
return return_value;
}

int16_t mems_quick_read(uint8_t type, UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	uint8_t receivebuffer_8[10];
	HAL_StatusTypeDef spi_status;
    uint8_t sendbuffer_8[3];
    int16_t return_value=0;
    sendbuffer_8[0]=type;
    sendbuffer_8[1]=0x00;
    sendbuffer_8[2]=0x00;

    HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 3, 5000);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);


	if(spi_status==HAL_OK){
		return_value= (int16_t)(((receivebuffer_8[1])<<8) | ((receivebuffer_8[2])));
	}
return return_value;
}

int8_t mems_single_read(uint8_t type, UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	uint8_t receivebuffer_8[10];
	HAL_StatusTypeDef spi_status;
    uint8_t sendbuffer_8[2];
    sendbuffer_8[0]=type;
    sendbuffer_8[1]=0x00;
    int8_t return_value=0;
    HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 2, 5000);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);
	if(spi_status==HAL_OK){
		return_value= (int8_t)(receivebuffer_8[1]);

	}
return return_value;
}

int16_t gyro_three_axis_read(int16_t *array, UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	HAL_StatusTypeDef spi_status;
    uint8_t sendbuffer_8[7];
    uint8_t receivebuffer_8[10];
    sendbuffer_8[0]=GYRO_XOH;
    sendbuffer_8[1]=0x00;
    sendbuffer_8[2]=0x00;
    sendbuffer_8[3]=0x00;
    sendbuffer_8[4]=0x00;
    sendbuffer_8[5]=0x00;
    sendbuffer_8[6]=0x00;

    HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 7, 5000);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);


	if(spi_status==HAL_OK){
		*(array)= (int16_t)(((receivebuffer_8[1])<<8) | ((receivebuffer_8[2])));
		*(array+1)= (int16_t)(((receivebuffer_8[3])<<8) | ((receivebuffer_8[4])));
		*(array+2)= (int16_t)(((receivebuffer_8[5])<<8) | ((receivebuffer_8[6])));
	}
return 0;
}

int16_t acc_three_axis_read(int16_t *array, UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr){
	HAL_StatusTypeDef spi_status;
	uint8_t sendbuffer_8[7];
	uint8_t receivebuffer_8[10];
    sendbuffer_8[0]=ACC_XOH;
    sendbuffer_8[1]=0x00;
    sendbuffer_8[2]=0x00;
    sendbuffer_8[3]=0x00;
    sendbuffer_8[4]=0x00;
    sendbuffer_8[5]=0x00;
    sendbuffer_8[6]=0x00;

    HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi_ptr, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 7, 5000);
	if(spi_status==HAL_ERROR) char_Print(huart_ptr,"error\n\r");
	HAL_GPIO_WritePin(GPIOB,CS_Pin,GPIO_PIN_SET);


	if(spi_status==HAL_OK){
		*(array)= (int16_t)(((receivebuffer_8[1])<<8) | ((receivebuffer_8[2])));
		*(array+1)= (int16_t)(((receivebuffer_8[3])<<8) | ((receivebuffer_8[4])));
		*(array+2)= (int16_t)(((receivebuffer_8[5])<<8) | ((receivebuffer_8[6])));
	}
return 0;
}



