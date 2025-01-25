/*
 * app.c
 *
 *  Created on: Jan 18, 2025
 *      Author: steve
 */

#include "app.h"
#include <stdio.h>
#include <string.h>
#include "fatfs.h"
#define f_unmount(path) f_mount(0, path, 0)

extern UART_HandleTypeDef huart2;

uint8_t value[3];

void app() {
	// uart 초기화
	initUart(&huart2);
	// fafs 설정
	FATFS		*fatfs;
	FIL			*file;
	FRESULT	fresult;

	char message[100] = {0,};
	unsigned int	writeSize;
	unsigned int	readSize;
	// 메모리 할당
	fatfs = malloc(sizeof(FATFS));
	file = malloc(sizeof(FIL));
	// 디스크 마운트
	f_mount(fatfs, "0:", 0);
	// 파일 읽기
	fresult = f_open(file, "message.txt", FA_READ);
	if(fresult) printf("fail open message.txt\n");
	fresult = f_read(file, message, 100, &readSize);
	if(fresult) printf("fail read\n");
	f_close(file);
	// 파일 쓰기
	fresult = f_open(file, "message2.txt", FA_WRITE | FA_CREATE_ALWAYS);
	if(fresult) printf("fail open message2.txt\n");
	fresult = f_write(file, message, strlen(message), &writeSize);
	if(fresult) printf("fail write\n");
	f_close(file);
	// 디스크 언마운트
	f_unmount("0:");
	while(1) {

	}
}
