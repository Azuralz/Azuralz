#include "stm32f10x.h"                  // Device header

uint8_t ConutSensor_count;

void ConutSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//使能AFIO 
	
	GPIO_InitTypeDef GPIO_InitSturcture;
	GPIO_InitSturcture.GPIO_Mode =  GPIO_Mode_IPU;
	GPIO_InitSturcture.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitSturcture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitSturcture);//使能引脚
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);//链接EXIT

	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;//通道
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//选择中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//指定响应模式下降延上升延和双边延
	EXTI_Init(&EXTI_InitStructure);//初始化EXIT
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//链接NVIC指定响应等级
	
	NVIC_InitTypeDef NVIC_InitStructure;//Nvic参数结构体
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;//指定NVIC通道
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能或失能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority  = 1;//相应优先级
	NVIC_Init(&NVIC_InitStructure);//初始化NVIC
}

uint16_t ConutSensor_Get(void) 
{
	return ConutSensor_count;
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line14) == SET)//获取标志位	
	{
		ConutSensor_count ++;
		EXTI_ClearITPendingBit(EXTI_Line14);//清楚标志位
	}
}


