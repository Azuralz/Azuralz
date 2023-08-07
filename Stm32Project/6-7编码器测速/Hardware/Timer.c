#include "stm32f10x.h"                  // Device header

void Timer_Init (void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_InternalClockConfig(TIM2);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseIniture;
	TIM_TimeBaseIniture.TIM_ClockDivision = TIM_CKD_DIV1;		//分频模式
	TIM_TimeBaseIniture.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式
	TIM_TimeBaseIniture.TIM_Period = 10000-1;					//ARR自动重装器的值
	TIM_TimeBaseIniture.TIM_Prescaler = 7200-1;					//预分频器的值
	TIM_TimeBaseIniture.TIM_RepetitionCounter = 0;				//重复计数器的值
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseIniture);
	
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitTure;
	NVIC_InitTure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitTure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitTure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitTure);
	
	TIM_Cmd(TIM2, ENABLE);
}	

//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET);
//	{

//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//}	

