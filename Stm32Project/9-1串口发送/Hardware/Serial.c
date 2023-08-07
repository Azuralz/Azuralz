#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;//波特率
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Tx;//发送还是接收
	USART_InitStructure.USART_Parity = USART_Parity_No;//校验位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//停止位
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//数据位大小
	USART_Init(USART1, &USART_InitStructure);
	
	USART_Cmd(USART1, ENABLE); 
}

void Serial_SendByte(uint8_t data)
{
	USART_SendData(USART1, data);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	
}
void Serial_SendArray(uint8_t * Array , uint16_t length)
{
	uint16_t i;
	for(i = 0;i < length; i++)
	{
		Serial_SendByte(Array[i]);
	}
}
void Serial_SendString(uint8_t * String)
{
	uint16_t i;
	for(i = 0; String[i]!= '\0'; i++)
	{
		Serial_SendByte(String[i]);
	}
}

uint16_t Serial_Pow(uint16_t x ,uint16_t y)
{
	uint16_t i =1;
	while(y--)
	{
		i *= x;
	}
	return i;
}
void Serial_Num(uint16_t Num,uint8_t length)
{
	uint8_t i;
	for(i = 0;i < length;i++)
	{
		Serial_SendByte(Num / Serial_Pow(10 , length - i - 1) % 10 + '0');
	}
}

int fputc(int ch,FILE *f)
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}
