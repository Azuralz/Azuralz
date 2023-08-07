#include "stm32f10x.h"                  // Device header

uint16_t Size;

void MyDMA_Init(uint32_t Addra, uint32_t Addrb, uint16_t size1)
{
	Size = size1;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitTypeDef DMA_InitStructure; 
	DMA_InitStructure.DMA_PeripheralBaseAddr = Addra;//外设数据起始地址
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;//外设数据大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable;//外设数据存储是否递增
	DMA_InitStructure.DMA_MemoryBaseAddr = Addrb;//DMA存储的起始地址
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;//DMA存储的数据大小
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//指定DMA是否递增
	DMA_InitStructure.DMA_BufferSize = Size;//转运数据的大小
	DMA_InitStructure.DMA_M2M = DMA_M2M_Enable;//是否软件触发
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;//确定外设为源地址还是目标地址
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;//传输计数器重装
	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;//指定通道的软件优先级
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	
	DMA_Cmd(DMA1_Channel1, ENABLE);
}

void MyDMA_Transfor(void)
{
	DMA_Cmd(DMA1_Channel1, DISABLE);//修改转运数据大小时需关闭DMA
	DMA_SetCurrDataCounter(DMA1_Channel1, Size);//修改转运数据个数
	DMA_Cmd(DMA1_Channel1, ENABLE);//重启DMA
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);//判断是否转运完成
	DMA_ClearFlag(DMA1_FLAG_TC1);//清理标志位
}
