#include "stm32f10x.h"                  // Device header
#include <time.h>

uint16_t MYRTC_Time[] = {2023, 8, 12, 17, 06, 01};


void MYRTC_Setime(void);
void MYRTC_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);
	
	if(BKP_ReadBackupRegister(BKP_DR1) != 0X5A5A)
	{
		RCC_LSEConfig(RCC_LSE_ON);
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) != SET);
		
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
		RCC_RTCCLKCmd(ENABLE);
		
		RTC_WaitForSynchro();
		RTC_WaitForLastTask();
		
		RTC_SetPrescaler(32768 - 1);
		RTC_WaitForLastTask();
		
		MYRTC_Setime();
		BKP_WriteBackupRegister(BKP_DR1, 0X5A5A);
	}
	else
	{
		RTC_WaitForSynchro();
		RTC_WaitForLastTask();
	}
}


void MYRTC_Setime(void)
{
	time_t time_cnt;
	struct tm time_data;
	time_data.tm_year = MYRTC_Time[0] - 1900;
	time_data.tm_mon = MYRTC_Time[1] - 1;
	time_data.tm_mday = MYRTC_Time[2];
	time_data.tm_hour = MYRTC_Time[3];
	time_data.tm_min = MYRTC_Time[4];
	time_data.tm_sec = MYRTC_Time[5];
	
	time_cnt = mktime(&time_data) - 8 * 60 * 60;	
	RTC_SetCounter(time_cnt);
	RTC_WaitForLastTask();
}


void MYRTC_Readtime(void)
{
	time_t time_cnt;
	struct tm time_data;
	time_cnt = RTC_GetCounter() + 8 * 60 * 60;
	time_data = *localtime(&time_cnt);
	
	MYRTC_Time[0] = time_data.tm_year + 1900;
	MYRTC_Time[1] = time_data.tm_mon + 1;
	MYRTC_Time[2] = time_data.tm_mday;
	MYRTC_Time[3] = time_data.tm_hour;
	MYRTC_Time[4] = time_data.tm_min;
	MYRTC_Time[5] = time_data.tm_sec;
}

