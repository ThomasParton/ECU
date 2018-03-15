/*
 * debug.c
 *
 *  Created on: 28 nov. 2017
 *      Author: thomas
 */

#include "debug.h"
#include "stm32f4xx_hal.h"

void debugPrint(UART_HandleTypeDef *huart_ptr, char _out[]){
	HAL_UART_Transmit(huart_ptr, (uint8_t *) _out, strlen(_out), 10);
}


void debugPrintln(UART_HandleTypeDef *huart_ptr, char _out[]){
	HAL_UART_Transmit(huart_ptr, (uint8_t *) _out, strlen(_out), 10);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(huart_ptr, (uint8_t *) newline, 2, 10);
}

void debugReceive(UART_HandleTypeDef *huart_ptr){
	//HAL_UART_Receive(huart_ptr, (uint8_t *)test, 64, 1);
}

void intprint8b(UART_HandleTypeDef *huart_ptr, uint8_t variable){
	char string[8];
	string[0]=48 +(variable&0b00000001);
	string[1]=48 +((variable&0b00000010)>>1);
	string[2]=48 +((variable&0b00000100)>>2);
	string[3]=48 +((variable&0b00001000)>>3);
	string[4]=48 +((variable&0b00010000)>>4);
	string[5]=48 +((variable&0b00100000)>>5);
	string[6]=48 +((variable&0b01000000)>>6);
	string[7]=48 +((variable&0b10000000)>>7);
	HAL_UART_Transmit(huart_ptr,  (uint8_t *) string, 8, 10);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(huart_ptr, (uint8_t *) newline, 2, 10);
}

void intprint16b(UART_HandleTypeDef *huart_ptr, uint16_t variable){
	char string[16];
	string[0]=48 +(variable&0b0000000000000001);
	string[1]=48 +((variable&0b0000000000000010)>>1);
	string[2]=48 +((variable&0b0000000000000100)>>2);
	string[3]=48 +((variable&0b0000000000001000)>>3);
	string[4]=48 +((variable&0b0000000000010000)>>4);
	string[5]=48 +((variable&0b0000000000100000)>>5);
	string[6]=48 +((variable&0b0000000001000000)>>6);
	string[7]=48 +((variable&0b0000000010000000)>>7);
	string[8]=48 +((variable&0b0000000100000001)>>8);
	string[9]=48 +((variable&0b0000001000000010)>>9);
	string[10]=48 +((variable&0b0000010000000100)>>10);
	string[11]=48 +((variable&0b0000100000001000)>>11);
	string[12]=48 +((variable&0b0001000000010000)>>12);
	string[13]=48 +((variable&0b0010000000100000)>>13);
	string[14]=48 +((variable&0b0100000001000000)>>14);
	string[15]=48 +((variable&0b1000000010000000)>>15);
	HAL_UART_Transmit(huart_ptr,  (uint8_t *) string, 16, 10);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(huart_ptr, (uint8_t *) newline, 2, 10);
}


void led_write(uint8_t number, uint8_t enable){
	switch(number){
	case 1: HAL_GPIO_WritePin(GPIOD, LED1_Pin,enable); break;
	case 2: HAL_GPIO_WritePin(GPIOD, LED2_Pin,enable); break;
	case 3: HAL_GPIO_WritePin(GPIOD, LED3_Pin,enable); break;
	case 4: HAL_GPIO_WritePin(GPIOD, LED4_Pin,enable); break;
	case 5: HAL_GPIO_WritePin(GPIOD, LED5_Pin,enable); break;
	case 6: HAL_GPIO_WritePin(GPIOD, LED6_Pin,enable); break;
	}
}

void led_toggle(uint8_t number){
	switch(number){
	case 1: HAL_GPIO_TogglePin(GPIOD,LED1_Pin); break;
	case 2: HAL_GPIO_TogglePin(GPIOD,LED2_Pin); break;
	case 3: HAL_GPIO_TogglePin(GPIOD,LED3_Pin); break;
	case 4: HAL_GPIO_TogglePin(GPIOD,LED4_Pin); break;
	case 5: HAL_GPIO_TogglePin(GPIOD,LED5_Pin); break;
	case 6: HAL_GPIO_TogglePin(GPIOD,LED6_Pin); break;
	}
}


