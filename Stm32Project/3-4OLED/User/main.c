#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "ConutSensor.h"

int main(void)
{
	OLED_Init();
	ConutSensor_Init();
	OLED_ShowString(1, 1, "Count:");
	while(1)
	{
		OLED_ShowNum(1, 7, ConutSensor_Get(), 7);
	}
}
