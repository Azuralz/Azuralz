#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "ConutSensor.h"
#include "MyDMA.h"

uint8_t data1[] = {0X01, 0X02, 0X03, 0X04};
uint8_t data2[] = {0};

int main(void)
{
	OLED_Init();
	MyDMA_Init((uint32_t)data1, (uint32_t)data2, 4);
	
	OLED_ShowString(1, 1, "data1");
	OLED_ShowString(3, 1, "data2");
	OLED_ShowHexNum(1, 8, (uint32_t)&data1, 8);
	OLED_ShowHexNum(3, 8, (uint32_t)&data2, 8);	
	while(1)
	{
		data1[0]++;
		data1[1]++;
		data1[2]++;
		data1[3]++;
		
		OLED_ShowHexNum(2, 1, data1[0], 2);
		OLED_ShowHexNum(2, 4, data1[1], 2);
		OLED_ShowHexNum(2, 7, data1[2], 2);
		OLED_ShowHexNum(2, 10, data1[3], 2);
		OLED_ShowHexNum(4, 1, data2[0], 2);
		OLED_ShowHexNum(4, 4, data2[1], 2);
		OLED_ShowHexNum(4, 7, data2[2], 2);
		OLED_ShowHexNum(4, 10, data2[3], 2);
		Delay_ms(1000);
		
		MyDMA_Transfor();
		
		OLED_ShowHexNum(2, 1, data1[0], 2);
		OLED_ShowHexNum(2, 4, data1[1], 2);
		OLED_ShowHexNum(2, 7, data1[2], 2);
		OLED_ShowHexNum(2, 10, data1[3], 2);
		OLED_ShowHexNum(4, 1, data2[0], 2);
		OLED_ShowHexNum(4, 4, data2[1], 2);
		OLED_ShowHexNum(4, 7, data2[2], 2);
		OLED_ShowHexNum(4, 10, data2[3], 2);
		Delay_ms(1000);
	}
}
