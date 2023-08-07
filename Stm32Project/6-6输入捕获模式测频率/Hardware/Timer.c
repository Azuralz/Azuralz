#include "stm32f10x.h"                  // Device header

void Timer_Init (void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);		//开启内部时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitTure;
	GPIO_InitTure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitTure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTure);
	
	TIM_ETRClockMode1Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_Inverted, 0X00);					//时钟模式配置
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseIniture;
	TIM_TimeBaseIniture.TIM_ClockDivision = TIM_CKD_DIV1;		//分频模式
	TIM_TimeBaseIniture.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式
	TIM_TimeBaseIniture.TIM_Period = 10 - 1 ;					//ARR自动重装器的值
	TIM_TimeBaseIniture.TIM_Prescaler = 1 - 1;					//预分频器的值
	TIM_TimeBaseIniture.TIM_RepetitionCounter = 0;				//重复计数器的值
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseIniture);				//时基单元配置
	
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);					//使能中断
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitTure;
	NVIC_InitTure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitTure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitTure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitTure);									//NVIC通道配置
	
	TIM_Cmd(TIM2, ENABLE);
}	

uint16_t Timer_GetCount(void)
{

		return TIM_GetCounter(TIM2);
}

//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET);
//	{

//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//}	

