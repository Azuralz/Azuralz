#include "stm32f10x.h"                  // Device header

void IC_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);			//开启TIM的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			//开启GPIO口的时钟
	
	GPIO_InitTypeDef GPIO_InitStructre;
	GPIO_InitStructre.GPIO_Mode = GPIO_Mode_IPU;					//模式上拉输入
	GPIO_InitStructre.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructre.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructre);							//初始化GPIO_0为复用推挽模式
	
	TIM_InternalClockConfig(TIM3);	
																	//初始化时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseIniStruture;
	TIM_TimeBaseIniStruture.TIM_ClockDivision = TIM_CKD_DIV1;		//分频模式
	TIM_TimeBaseIniStruture.TIM_CounterMode = TIM_CounterMode_Up;	//计数模式
	TIM_TimeBaseIniStruture.TIM_Period = 65536 - 1;					//ARR自动重装器的值
	TIM_TimeBaseIniStruture.TIM_Prescaler = 72 - 1;					//PSC预分频器的值
	TIM_TimeBaseIniStruture.TIM_RepetitionCounter = 0;				//重复计数器的值
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseIniStruture);
	
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;				//选择通道
	TIM_ICInitStructure.TIM_ICFilter = 0xF;							//选择滤波器
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;		//选择极性
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;			//预分频器
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;	//数据选择器的通道
	TIM_ICInit(TIM3, &TIM_ICInitStructure);							//配置输入捕获通道
	
	TIM_SelectInputTrigger(TIM3, TIM_TS_TI1FP1);											//配置TRGI触发源TF
	TIM_SelectSlaveMode(TIM3, TIM_SlaveMode_Reset);//配置从模式
	
	TIM_Cmd(TIM3, ENABLE);
}

uint32_t IC_GetFreq(void)
{
	return 1000000 / (TIM_GetCapture1(TIM3) + 1);
}
