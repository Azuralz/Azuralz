#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "ConutSensor.h"

int main(void)
{
	OLED_Init();
	OLED_SHOWpictur();
	
	while(1)
	{

	}
}
