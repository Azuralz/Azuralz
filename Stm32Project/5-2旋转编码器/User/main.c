#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "Encode.h"

int16_t Num;

int main(void)
{
	OLED_Init();
	Encode_Init();
	
	OLED_ShowString(1, 1, "Count:");
	
	while(1)
	{
		Num += Encode_Get();
		OLED_ShowSignedNum(1, 7, Num, 5);
	}
}
