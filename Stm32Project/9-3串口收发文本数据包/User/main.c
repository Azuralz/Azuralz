#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "Serial.h"
#include "string.h"
#include "LED.h"

uint8_t KeyNum;
int main(void)
{
	OLED_Init();
	Serial_Init();
	LED_Init();
	
	OLED_ShowString(1, 1, "TXPacket");
	OLED_ShowString(3, 1, "RXPacket");


	while(1)
	{
		if(Serial_RXflag == 1)
		{
			OLED_ShowString(4, 1, "                ");
			OLED_ShowString(4, 1, Serial_RXPacket);
			if(strcmp(Serial_RXPacket, "LED_ON") == 0)
			{
				LED1_ON();
				Serial_SendString("LED_ON_OK\r\n");
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "OLED_ON_OK");
			}
			else if(strcmp(Serial_RXPacket, "LED_OFF") == 0)
			{
				LED1_OFF();
				Serial_SendString("LED_OFF_OK\r\n");
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "OLED_OFF_OK");
			}
			else
			{
				Serial_SendString("ERROR_COMMAND\r\n");
				OLED_ShowString(2, 1, "                ");
				OLED_ShowString(2, 1, "ERROR_COMMAND");
			}
			Serial_RXflag = 0;
		}
	}
}
