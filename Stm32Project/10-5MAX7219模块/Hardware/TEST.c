#include "stm32f10x.h"                  // Device header
#include "MYSPI.h"





void Init7219(uint8_t work_state, uint8_t test_state, uint8_t decode_nums,
              uint8_t display_nums, uint8_t Luminance)     
{
	MYSPI_Init();
	MYSPI_Start();
	MYSPI_SwapByte(0X0C);	    // 工作模式选择   1:正常工作  0:掉电模式
	MYSPI_SwapByte(work_state);
	MYSPI_Stop();
	MYSPI_Start();
	MYSPI_SwapByte(0X0F);	    // 测试模式开关   1:测试模式  0:正常工作
	MYSPI_SwapByte(test_state);
	MYSPI_Stop();
	MYSPI_Start();
	MYSPI_SwapByte(0X09);	// 解码模式选择   8个位分别控制8个LED是否解码,'1'为BCD解码,'0'为不解码
	MYSPI_SwapByte(decode_nums);
	MYSPI_Stop();
	MYSPI_Start();
	MYSPI_SwapByte(0X0B);	// 扫描方式选择   0-7 设置扫描1-8个LED
	MYSPI_SwapByte(display_nums);
	MYSPI_Stop();
	MYSPI_Start();
	MYSPI_SwapByte(0X0A);	    // 初始亮度设置   0-15设置1-16档亮度
	MYSPI_SwapByte(Luminance);
	MYSPI_Stop();
}

void MAX7219_SendData(uint8_t Address, uint8_t Data)
{
	MYSPI_Start();
	MYSPI_SwapByte(Address);
	MYSPI_SwapByte(Data);
	MYSPI_Stop();
}

void Max7219_Clear(void)
{
	MYSPI_Start();
	MAX7219_SendData(0X01, 0x00);
	MAX7219_SendData(0x02, 0x00);
	MAX7219_SendData(0x03, 0x00);
	MAX7219_SendData(0X04, 0x00);
	MAX7219_SendData(0X05, 0x00);
	MAX7219_SendData(0x06, 0x00);
	MAX7219_SendData(0x07, 0x00);
	MAX7219_SendData(0X08, 0x00);
	MYSPI_Stop();	
}





