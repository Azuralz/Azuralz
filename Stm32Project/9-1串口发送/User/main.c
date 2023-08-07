#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "ConutSensor.h"
#include "Serial.h"

int main(void)
{
	OLED_Init();
	
	Serial_Init();
	
//	Serial_SendByte(0x88);
//	uint8_t arr[] = {0x99, 0x88, 0x66, 0x77};
//	Serial_SendArray(arr, 4);
//	Serial_SendString("Hellow,wrold!\t\n");
//	Serial_SendString("1");
//	Serial_Num(1982, 4);
//	printf("Num=%d\r\n",666);
//	char string[100];
//	sprintf(string, "Num=%d\r\n",666);
//	Serial_SendString(string);
	Serial_Printf("Num = %d\r\n", 666);
	while(1)
	{
	
	}
}
