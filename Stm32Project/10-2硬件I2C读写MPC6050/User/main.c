#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU.h"

MPU6050_GetValue A;
uint8_t ID;

int main(void)
{	
	OLED_Init();
	MPU_Init();
	ID = MPU_GetID();
	
	OLED_ShowString(1, 1, "ID:");
	OLED_ShowHexNum(1, 4, ID, 2);
	while (1)
	{
		MPU_GetData(&A);
		OLED_ShowSignedNum(2, 1, A.AccX, 5);
		OLED_ShowSignedNum(3, 1, A.AccY, 5);
		OLED_ShowSignedNum(4, 1, A.AccZ, 5);
		OLED_ShowSignedNum(2, 8, A.GyroX, 5);
		OLED_ShowSignedNum(3, 8, A.GyroY, 5);
		OLED_ShowSignedNum(4, 8, A.GyroZ, 5);
	}
}
