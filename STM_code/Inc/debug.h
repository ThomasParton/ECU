/*
 * debug.h
 *
 *  Created on: 28 nov. 2017
 *      Author: thomas
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "stm32f4xx_hal.h"
void debugPrint(UART_HandleTypeDef *huart_ptr, char _out[]);
void debugPrintln(UART_HandleTypeDef *huart_ptr, char _out[]);
void debugReceive(UART_HandleTypeDef *huart_ptr);
void intprint8b(UART_HandleTypeDef *huart_ptr, uint8_t variable);
void intprint16b(UART_HandleTypeDef *huart_ptr, uint16_t variable);
void led_write(uint8_t number, uint8_t enable);
void led_toggle(uint8_t number);
#endif /* DEBUG_H_ */
