#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>

uint8_t Serial_RXPacket[4];
uint8_t Serial_TXPacket[4];
uint8_t Serial_RXflag;

void Serial_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//开启GPIO时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//开启USART通信的时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出接发送脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入接接收脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;//波特率
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;//发送还是接收
	USART_InitStructure.USART_Parity = USART_Parity_No;//校验位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//停止位
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//数据位大小
	USART_Init(USART1, &USART_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//开启USART的NVIC通道
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);

	USART_Cmd(USART1, ENABLE); 
}

void Serial_SendByte(uint8_t data)//发送字节
{
	USART_SendData(USART1, data);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	
}
void Serial_SendArray(uint8_t * Array , uint16_t length)//发送数组
{
	uint16_t i;
	for(i = 0;i < length; i++)
	{
		Serial_SendByte(Array[i]);
	}
}
void Serial_SendString(char * String)//发送字符串
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
void Serial_Num(uint16_t Num,uint8_t length)//发送数字
{
	uint8_t i;
	for(i = 0;i < length;i++)
	{
		Serial_SendByte(Num / Serial_Pow(10 , length - i - 1) % 10 + '0');
	}
}

int fputc(int ch,FILE *f)//切换printf的输出流
{
	Serial_SendByte(ch);
	return ch;
}

void Serial_Printf(char *format, ...)//多串口使用printf
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendString(String);
}

uint8_t Serial_GetRxflag(void)//获得接收标志位
{
	if(Serial_RXflag == 1)
	{
		Serial_RXflag = 0;
		return 1;
	}
	return 0;	
}

void Serial_SendPackt(void)
{
	Serial_SendByte(0XFF);
	Serial_SendArray(Serial_TXPacket, 4);
	Serial_SendByte(0XFE);
}



void USART1_IRQHandler(void)//中断函数
{
	static uint8_t RXstate = 0;
	static uint8_t RXsize = 0;
	if(USART_GetFlagStatus(USART1, USART_IT_RXNE) == SET)
	{
		uint8_t Rxdata = USART_ReceiveData(USART1);
		if(RXstate == 0)
		{
			if(Rxdata == 0xFF)
			{
				RXstate = 1;
				RXsize = 0;
			}
		}
		else if(RXstate == 1)
		{
			Serial_RXPacket[RXsize] = Rxdata;
			RXsize ++;
			if(RXsize >=4)
			{
				RXstate = 2;
			}
		}
		else if(RXstate == 2)
		{
			if(Rxdata == 0xFE)
			{
				RXstate = 0;
				Serial_RXflag = 1;
			}
		}
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
}
