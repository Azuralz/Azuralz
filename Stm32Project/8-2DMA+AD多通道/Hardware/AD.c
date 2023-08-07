#include "stm32f10x.h"                  // Device header

uint16_t AD_Value[4];

void AD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);//开启ADC的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStucture;
	GPIO_InitStucture.GPIO_Mode = GPIO_Mode_AIN;//模拟输入模式
	GPIO_InitStucture.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStucture.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStucture);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);//选择通道配置
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_55Cycles5);
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;//连续还是单次
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//数据对齐方式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//选择触发源，软件触发
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//ADC模式独立模式还是双adc模式
	ADC_InitStructure.ADC_NbrOfChannel = 4;//扫描通道数
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;//扫描模式开启或关闭
	ADC_Init(ADC1, &ADC_InitStructure);
	
	
	
	DMA_InitTypeDef DMA_InitStructure; 
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;//外设数据起始地址
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//外设数据大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设数据存储是否递增
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)AD_Value;//DMA存储的起始地址
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//DMA存储的数据大小
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//指定DMA是否递增
	DMA_InitStructure.DMA_BufferSize = 4;//转运数据的大小
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//是否软件触发
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;//确定外设为源地址还是目标地址
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//传输计数器重装
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//指定通道的软件优先级
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	
	DMA_Cmd(DMA1_Channel1, ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1);//开启复位校准
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);//返回ADC复位校准器的状态0为校准完成,RSTCLA在转换完成后自动清零
	ADC_StartCalibration(ADC1);//开启校准
	while(ADC_GetCalibrationStatus(ADC1) == SET);//返回ADC校准器的状态0为校准完成//
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

//void AD_GetValue(void)	
//{
//	
//	DMA_Cmd(DMA1_Channel1, DISABLE);//修改转运数据大小时需关闭DMA
//	DMA_SetCurrDataCounter(DMA1_Channel1, 4);//修改转运数据个数
//	DMA_Cmd(DMA1_Channel1, ENABLE);//重启DMA
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);	//开启软件触发
//	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);//判断是否转运完成
//	DMA_ClearFlag(DMA1_FLAG_TC1);//清理标志位
//}
