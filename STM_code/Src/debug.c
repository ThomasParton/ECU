/*
 * debug.c
 *
 *  Created on: 28 nov. 2017
 *      Author: thomas
 */

#include "debug.h"
#include "stm32f4xx_hal.h"

void unsign_print(UART_HandleTypeDef *huart_ptr, uint8_t var){
	char str[32];
	sprintf(str, "%u\n\r", var);
	HAL_UART_Transmit(huart_ptr,  (uint8_t *) str,strlen(str), 10);

}

void signed_print(UART_HandleTypeDef *huart_ptr, int16_t var){
	char str[32];
	sprintf(str, "%d\n\r", var);
	HAL_UART_Transmit(huart_ptr,  (uint8_t *) str,strlen(str), 10);

}

void float_print(UART_HandleTypeDef *huart_ptr, float var){
	char str[32];
	sprintf(str, "value: %e\n\r", var);
	HAL_UART_Transmit(huart_ptr,  (uint8_t *) str,strlen(str), 10);

}
void char_Print(UART_HandleTypeDef *huart_ptr, char _out[]){
	HAL_UART_Transmit(huart_ptr, (uint8_t *) _out, strlen(_out), 10);
}




void debugReceive(UART_HandleTypeDef *huart_ptr){
	//HAL_UART_Receive(huart_ptr, (uint8_t *)test, 64, 1);
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


