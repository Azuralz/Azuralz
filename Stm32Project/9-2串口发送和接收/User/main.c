#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "ConutSensor.h"
#include "Serial.h"

uint8_t RXdata;

int main(void)
{
	OLED_Init();
	OLED_ShowString(1, 1, "RXdata:");
	Serial_Init();
	
	
	while(1)
	{
		if(Serial_GetRxflag() == 1)
		{
			RXdata = Serial_GetData();
			Serial_SendByte(RXdata);
			OLED_ShowHexNum(1, 8, RXdata, 2); 
		}
	}
}
