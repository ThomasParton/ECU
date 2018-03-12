/*
 * memory
 *
 *  Created on: 15 feb. 2018
 *      Author: thomas
 */

#ifndef MEMORY_H_
#define MEMORY_H_
#include "stm32f4xx_hal.h"
#include "debug.h"

#define READ_CODE 	0x1B
#define WRITE_CODE 	0x82
#define STATUS_CODE	0xD7
#define ID_CODE 	0x9F

uint8_t mem_read(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi);
uint8_t mem_write(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi);
uint8_t mem_id(UART_HandleTypeDef *huart,SPI_HandleTypeDef *hspi);

#endif /* MEMORY_H_ */
