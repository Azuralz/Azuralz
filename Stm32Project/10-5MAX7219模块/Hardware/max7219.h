#ifndef __MAX7219_H
#define __MAX7219_H

#include "stm32f10x.h"
#include "sys.h"

#define SPI_IS_HARDWARE 1  //1：硬件SPI；0：软件模拟SPI

#define Max7219_pinDIN_GPIO GPIO_Pin_7
#define Max7219_pinCS_GPIO  GPIO_Pin_3
#define Max7219_pinCLK_GPIO GPIO_Pin_5
#define SPI_MISO_GPIO       GPIO_Pin_6//未使用到

#define Max7219_pinDIN PAout(7)
#define Max7219_pinCS  PAout(3)
#define Max7219_pinCLK PAout(5)

void Max7219_GPIO_Init(void);
void Write_Max7219_byte(u8 data);
void Write_Max7219(u8 addr,u8 dat);
void Init_MAX7219(void);

#endif
