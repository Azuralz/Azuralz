#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "KEY.h"

uint16_t ArrW[] = {0X1234, 0X5678};
uint16_t ArrR[2];
uint8_t KeyNum;

int main(void)
{
	OLED_Init();
	Key_Init();
	
	OLED_ShowString(1, 1, "W:");
	OLED_ShowString(2, 1, "R:");
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
	
	PWR_BackupAccessCmd(ENABLE);

	while(1)
	{
		KeyNum = Key_GetNum();
		if(KeyNum == 1)
		{
			ArrW[0] ++;
			ArrW[1] ++;
			BKP_WriteBackupRegister(BKP_DR1, ArrW[0]);
			BKP_WriteBackupRegister(BKP_DR2, ArrW[1]);
			OLED_ShowHexNum(1, 3, ArrW[0], 4);
			OLED_ShowHexNum(1, 8, ArrW[1], 4);
		}
		ArrR[0] = BKP_ReadBackupRegister(BKP_DR1);
		ArrR[1] = BKP_ReadBackupRegister(BKP_DR2);
		OLED_ShowHexNum(2, 3, ArrR[0], 4);
		OLED_ShowHexNum(2, 8, ArrR[1], 4);
	}
}
