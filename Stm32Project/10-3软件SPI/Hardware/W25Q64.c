#include "stm32f10x.h"                  // Device header
#include "MYSPI.h"
#include "W25Q64_INS.h"

void W25Q64_Init(void)
{
	MYSPI_Init();
}

void W25Q64_GetID(uint8_t *MID, uint16_t *DID)
{
	MYSPI_Start();
	MYSPI_SwapByte(0x9F);
	*MID = MYSPI_SwapByte(0xFF);
	*DID = MYSPI_SwapByte(0xFF);
	*DID <<= 8;
	*DID |= MYSPI_SwapByte(0xFF);
	MYSPI_Stop();
}

void W25Q64_WritEnable(void)
{
	MYSPI_Start();
	MYSPI_SwapByte(W25Q64_WRITE_ENABLE);
	MYSPI_Stop();
}

void W25Q64_WritBusy(void)
{
	uint32_t timeout;
	MYSPI_Start();
	MYSPI_SwapByte(W25Q64_READ_STATUS_REGISTER_1);
	timeout =100000;
	while((MYSPI_SwapByte(W25Q64_DUMMY_BYTE) & 0x01) == 0x01)
	{
		timeout--;
		if(timeout == 0)
		{
			break;
		}
	}
	MYSPI_Stop();
}

void W25Q64_PageProgram(uint32_t Address, uint8_t *DataArray, uint32_t Count)
{
	uint32_t i;
	W25Q64_WritEnable();
	MYSPI_Start();
	MYSPI_SwapByte(W25Q64_PAGE_PROGRAM);
	MYSPI_SwapByte(Address >> 16);
	MYSPI_SwapByte(Address >> 8);
	MYSPI_SwapByte(Address);
	for(i = 0; i < Count; i++)
	{
		MYSPI_SwapByte(DataArray[i]);
	}
	MYSPI_Stop();
	W25Q64_WritBusy();
}

void W25Q64_SectorErase(uint32_t Address)
{
	W25Q64_WritEnable();
	MYSPI_Start();
	MYSPI_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	MYSPI_SwapByte(Address >> 16);
	MYSPI_SwapByte(Address >> 8);
	MYSPI_SwapByte(Address);
	MYSPI_Stop();
	W25Q64_WritBusy();
}

void W25Q64_ReadData(uint32_t Address, uint8_t *DataArray, uint32_t Count)
{
	uint32_t i;
	MYSPI_Start();
	MYSPI_SwapByte(W25Q64_READ_DATA);
	MYSPI_SwapByte(Address >> 16);
	MYSPI_SwapByte(Address >> 8);
	MYSPI_SwapByte(Address);
	for(i = 0; i < Count; i++)
	{
		DataArray[i] = MYSPI_SwapByte(W25Q64_DUMMY_BYTE);		
	}
	MYSPI_Stop();
}



