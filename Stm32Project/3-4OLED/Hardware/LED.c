#include "stm32f10x.h"                  // Device header
#include "stm32f10x.h"                  // Device header 


void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能GPIO_A时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;//输入参数
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化
}

void LED1_Turn(void)  //LED1反转
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
	}
}

void LED2_Turn(void) //LED2反转
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2) == 0)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
	}
}

void LED1_ON(void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1);
}

void LED1_OFF(void) //熄灭LED1
{
	GPIO_SetBits(GPIOA, GPIO_Pin_1);
}

void LED2_ON(void)//开启
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_2);
}

void LED2_OFF(void)
{
	GPIO_SetBits(GPIOA, GPIO_Pin_2);
}