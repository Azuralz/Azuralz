#ifndef __SERIAL_H
#define __SERIAL_H
#include <stdio.h>

void Serial_Init(void);
void Serial_SendByte(uint8_t data);
void Serial_SendArray(uint8_t * Array , uint16_t length);
void Serial_SendString(uint8_t * String);
void Serial_Num(uint16_t Num,uint8_t length);
uint16_t Serial_Pow(uint16_t x ,uint16_t y);
void Serial_Printf(char *format, ...);

#endif
