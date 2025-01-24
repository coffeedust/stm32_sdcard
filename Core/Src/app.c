/*
 * app.c
 *
 *  Created on: Jan 18, 2025
 *      Author: steve
 */

#include "app.h"
#include <stdio.h>
#include "fatfs.h"

extern UART_HandleTypeDef huart2;

uint8_t value[3];

void app() {
	initUart(&huart2);

	while(1) {

	}
}
