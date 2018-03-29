/*
 * debug.h
 *
 *  Created on: 28 nov. 2017
 *      Author: thomas
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "stm32f4xx_hal.h"
void unsign_print(UART_HandleTypeDef *huart_ptr, uint8_t var);
void signed_print(UART_HandleTypeDef *huart_ptr, int16_t var);
void float_print(UART_HandleTypeDef *huart_ptr, float var);
void char_Print(UART_HandleTypeDef *huart_ptr, char _out[]);
void led_write(uint8_t number, uint8_t enable);
void led_toggle(uint8_t number);
#endif /* DEBUG_H_ */
