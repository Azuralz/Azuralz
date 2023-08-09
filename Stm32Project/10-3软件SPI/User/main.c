#include "stm32f10x.h"     // Device header
#include "Delay.h"         //shijian
#include "OLED.h"
#include "W25Q64.h"

uint8_t MID;
uint16_t DID;
uint8_t ArrWrite[] = {0xB1, 0xFA, 0x33, 0x44};
uint8_t ArrRead[] = {0};

int main(void)
{
	OLED_Init();
	W25Q64_Init();
	
	W25Q64_GetID(&MID, &DID);
	OLED_ShowString(1, 1, "MID:");
	OLED_ShowHexNum(1, 5, MID, 2);
	OLED_ShowString(1, 8, "DID:");
	OLED_ShowHexNum(1, 12, DID, 4);
	
	W25Q64_SectorErase(0x00);
	W25Q64_PageProgram(0x00, ArrWrite, 4);
	W25Q64_ReadData(0x00,ArrRead, 4);
	
	OLED_ShowHexNum(3, 1, ArrWrite[0], 2);
	OLED_ShowHexNum(3, 5, ArrWrite[1], 2);
	OLED_ShowHexNum(3, 9, ArrWrite[2], 2);
	OLED_ShowHexNum(3, 13, ArrWrite[3], 2);
	
	OLED_ShowHexNum(2, 1, ArrRead[0], 2);
	OLED_ShowHexNum(2, 5, ArrRead[1], 2);
	OLED_ShowHexNum(2, 9, ArrRead[2], 2);
	OLED_ShowHexNum(2, 13, ArrRead[3], 2);
	while(1)
	{
		
	}
}
