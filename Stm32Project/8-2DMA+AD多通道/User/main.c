#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "AD.h"



int main(void)
{
	OLED_Init();
	AD_Init();
	OLED_ShowString(1, 1, "Value1:");
	OLED_ShowString(2, 1, "Value2:");
	OLED_ShowString(3, 1, "Value3:");
	OLED_ShowString(4, 1, "Value4:");
	while(1)
	{
		
		OLED_ShowNum(1, 8, AD_Value[0], 4);
		OLED_ShowNum(2, 8, AD_Value[1], 4);
		OLED_ShowNum(3, 8, AD_Value[2], 4);
		OLED_ShowNum(4, 8, AD_Value[3], 4);
		Delay_ms(100);
	}
}
