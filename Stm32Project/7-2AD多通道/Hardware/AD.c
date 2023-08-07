#include "stm32f10x.h"                  // Device header

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);//开启ADC的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStucture;
	GPIO_InitStucture.GPIO_Mode = GPIO_Mode_AIN;//模拟输入模式
	GPIO_InitStucture.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStucture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStucture);
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//连续还是单次
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//数据对齐方式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//选择触发源，软件触发
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//ADC模式独立模式还是双adc模式
	ADC_InitStructure.ADC_NbrOfChannel = 1;//扫描通道数
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;//扫描模式开启或关闭
	ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1);//开启复位校准
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);//返回ADC复位校准器的状态0为校准完成,RSTCLA在转换完成后自动清零
	ADC_StartCalibration(ADC1);//开启校准
	while(ADC_GetCalibrationStatus(ADC1) == SET);//返回ADC校准器的状态0为校准完成//
}

uint16_t AD_GetValue(uint8_t ADC_Channel)	
{
	ADC_RegularChannelConfig(ADC1, ADC_Channel, 1, ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);	//开启软件触发
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);//获取EOC的标志位
	return ADC_GetConversionValue(ADC1);//获取转换值
}
