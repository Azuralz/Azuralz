#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "Timer.h"
#include "Encoder.h"



int main(void)
{
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1, 1, "Speed:");
	
	while(1)
	{
		OLED_ShowSignedNum(1, 7, Encoder_Get(), 5);
		Delay_ms(1000);
	}
}

