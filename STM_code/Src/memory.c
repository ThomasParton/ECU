/*
 * memory
 *
 *  Created on: 15 feb. 2018
 *      Author: thomas
 */
#include "main.h"
#include "memory.h"
uint8_t sendbuffer_8[528];
uint8_t receivebuffer_8[sizeof(sendbuffer_8)];
uint8_t status;
HAL_StatusTypeDef spi_status;

uint8_t mem_status(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi){
	sendbuffer_8[0]=STATUS_CODE;
	sendbuffer_8[1]=0x00;
	sendbuffer_8[2]=0x00;
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 3, 5000);
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_SET);
	status=(receivebuffer_8[1]>>7)&0x01;
	if(spi_status==HAL_ERROR) debugPrintln(huart,"error while mem status");
	debugPrintln(huart,"status");
	intprint(huart,status);
	debugPrintln(huart,"\n");
	return status;
}

uint8_t mem_write(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi){
	sendbuffer_8[0]=WRITE_CODE;
	sendbuffer_8[1]=0x00; //adr
	sendbuffer_8[2]=0x00;
	sendbuffer_8[3]=0x00;

	sendbuffer_8[4]=0xAA; //data
	sendbuffer_8[5]=0xBB;
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 6, 5000);
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_SET);

	if(spi_status==HAL_ERROR) debugPrintln(huart,"error while mem write");
	debugPrintln(huart,"done write");
	debugPrintln(huart,"\n");
return 0;
}

uint8_t mem_read(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi){
	sendbuffer_8[0]=READ_CODE;
	sendbuffer_8[1]=0x00; //adr
	sendbuffer_8[2]=0x00;
	sendbuffer_8[3]=0x00;

	sendbuffer_8[4]=0x00; //dummy
	sendbuffer_8[5]=0x00;

	sendbuffer_8[6]=0x00; //reading
	sendbuffer_8[7]=0x00;
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 8, 5000);
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_SET);

	if(spi_status==HAL_ERROR) debugPrintln(huart,"error while mem read");

	debugPrintln(huart,"reading");
	intprint(huart, receivebuffer_8[6]);
	intprint(huart, receivebuffer_8[7]);
	debugPrintln(huart,"\n");

return 0;
}


uint8_t mem_id(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi){
	sendbuffer_8[0]=ID_CODE;
	sendbuffer_8[1]=0x00;
	sendbuffer_8[2]=0x00;
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_RESET);
	spi_status=HAL_SPI_TransmitReceive(hspi, (uint8_t*)sendbuffer_8, (uint8_t *)receivebuffer_8, 3, 5000);
	HAL_GPIO_WritePin(GPIOA,MEM_CS_Pin,GPIO_PIN_SET);

	if(spi_status==HAL_ERROR) debugPrintln(huart,"error while mem id");
	intprint(huart, receivebuffer_8[0]);
	intprint(huart, receivebuffer_8[1]);
	intprint(huart, receivebuffer_8[2]);
	debugPrintln(huart,"\n");
	return 0;
}
