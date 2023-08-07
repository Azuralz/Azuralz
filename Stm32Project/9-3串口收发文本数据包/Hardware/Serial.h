#ifndef __SERIAL_H
#define __SERIAL_H
#include <stdio.h>

extern char Serial_RXPacket[100];
extern uint8_t Serial_RXflag;

void Serial_Init(void);
void Serial_SendByte(uint8_t data);
void Serial_SendArray(uint8_t * Array , uint16_t length);
void Serial_SendString(uint8_t * String);
void Serial_Num(uint16_t Num,uint8_t length);
void Serial_Printf(char *format, ...);


#endif
