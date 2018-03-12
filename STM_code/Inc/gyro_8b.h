/*
 * gyro2.h
 *
 *  Created on: 27 feb. 2018
 *      Author: thomas
 */

#ifndef GYRO_8B_H_
#define GYRO_8B_H_

/*
 * gyro.h
 *
 *  Created on: 27 nov. 2017
 *      Author: thomas
 */

#ifndef GYRO_H_
#define GYRO_H_
#include "stm32f4xx_hal.h"
#include "debug.h"

#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C
#define FIFO_EN 0x23
#define CONFIG 0x1A
#define SMPLRT_DIV 0x19
#define GYRO_CONFIG 0x1B
#define GYRO_X_OFF 0x13
#define GYRO_Y_OFF 0x14
#define GYRO_Z_OFF 0x15
#define USER_CNTRL 0x6A
#define INT_PIN_CFG 0x37
#define ACC_CONFIG 0x1C
#define ACC_CONFIG2 0x1D

#define GYRO_XOH 0xC3
#define GYRO_XOL 0xC4
#define GYRO_YOH 0xC5
#define GYRO_YOL 0xC6
#define GYRO_ZOH 0xC7
#define GYRO_ZOL 0xC8

#define ACC_XOH 0xBB
#define ACC_XOL 0xBC
#define ACC_YOH 0xBD
#define ACC_YOL 0xBE
#define ACC_ZOH 0xBF
#define ACC_ZOL 0xC0


#define DATA_SIZE 18


void gyro_init8b(UART_HandleTypeDef *huart4,SPI_HandleTypeDef *hspi2);
uint8_t gyro_read(uint8_t type, UART_HandleTypeDef *huart4,SPI_HandleTypeDef *hspi2);
void whoami8b(UART_HandleTypeDef *huart_ptr,SPI_HandleTypeDef *hspi_ptr);


#endif /* GYRO_H_ */


#endif /* GYRO_8B_H_ */
