#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "MYSPI.h"
#include "TEST.h"



int main(void)
{
	Init7219(0X01, 0X00, 0X00, 0X07, 0X0F);
	
	while(1)
	{
		Max7219_Clear();
		MAX7219_SendData(0X01, 0X00);
		Delay_ms(500);
		MAX7219_SendData(0x02, 0x30);
		Delay_ms(500);
		MAX7219_SendData(0x03, 0x48);
		Delay_ms(500);
		MAX7219_SendData(0X04, 0x44);
		Delay_ms(500);
		MAX7219_SendData(0X05, 0x22);
		Delay_ms(500);
		MAX7219_SendData(0x06, 0x44);
		Delay_ms(500);
		MAX7219_SendData(0x07, 0x48);
		Delay_ms(500);
		MAX7219_SendData(0X08, 0x30);
		Delay_ms(5000);
	}
}
