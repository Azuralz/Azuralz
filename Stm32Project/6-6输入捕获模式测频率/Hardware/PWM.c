#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);			//开启TIM的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			//开启GPIO口的时钟
	
	GPIO_InitTypeDef GPIO_InitStructre;
	GPIO_InitStructre.GPIO_Mode = GPIO_Mode_AF_PP;					//模式推挽输出
	GPIO_InitStructre.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructre.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructre);							//初始化GPIO_0为复用推挽模式
	
	TIM_InternalClockConfig(TIM2);	
																	//初始化时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseIniStruture;
	TIM_TimeBaseIniStruture.TIM_ClockDivision = TIM_CKD_DIV1;		//分频模式
	TIM_TimeBaseIniStruture.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式
	TIM_TimeBaseIniStruture.TIM_Period = 100 - 1;					//ARR自动重装器的值
	TIM_TimeBaseIniStruture.TIM_Prescaler = 720 - 1;				//PSC预分频器的值
	TIM_TimeBaseIniStruture.TIM_RepetitionCounter = 0;				//重复计数器的值
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseIniStruture);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);							//给基础通道设置初始值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;				//设置输出比较的模式
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;		//设置输出比较的极性
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;    //使能失能
	TIM_OCInitStructure.TIM_Pulse = 0;								//CCR值
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);						//初始化比较单元通道
	
	TIM_Cmd(TIM2, ENABLE);
}

void PWM_SetCompare1(uint16_t Compare)								//修改CCR的值
{
	TIM_SetCompare1(TIM2, Compare);
}

void PWM_SetPrescaler(uint16_t Prescaler)							//用来修改PSC的值从而改变频率
{
	TIM_PrescalerConfig(TIM2, Prescaler, TIM_PSCReloadMode_Immediate);
}
