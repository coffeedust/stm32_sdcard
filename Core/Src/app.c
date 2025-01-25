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
	// uart 초기화
	initUart(&huart2);
	// fafs 설정
	while(1) {

	}
}
