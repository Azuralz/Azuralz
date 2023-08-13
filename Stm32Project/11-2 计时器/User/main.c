#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "MYRTC.h"


int main(void)
{
	OLED_Init();
	MYRTC_Init();
	OLED_ShowString(1, 1, "Date:xxxx:xx:xx");
	OLED_ShowString(2, 1, "Time:xx:xx:xx");
	OLED_ShowString(3, 1, "CNT:");
	
	while(1)
	{			
		OLED_ShowNum(3, 5, RTC_GetCounter(), 10);
		MYRTC_Readtime();
		OLED_ShowNum(1, 6, MYRTC_Time[0], 4);
		OLED_ShowNum(1, 11, MYRTC_Time[1], 2);
		OLED_ShowNum(1, 14, MYRTC_Time[2], 2);
		OLED_ShowNum(2, 6, MYRTC_Time[3], 2);
		OLED_ShowNum(2, 9, MYRTC_Time[4], 2);
		OLED_ShowNum(2, 12, MYRTC_Time[5], 2);
		OLED_ShowNum(3, 5, RTC_GetCounter(), 10);
	}
}
