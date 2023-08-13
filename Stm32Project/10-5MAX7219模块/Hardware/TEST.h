#ifndef __TEST_H
#define __TEST_H



void Init7219(uint8_t work_state, uint8_t test_state, uint8_t decode_nums,
              uint8_t display_nums, uint8_t Luminance);
void MAX7219_SendData(uint8_t Address, uint8_t Data);
void Max7219_Clear(void);
	
#endif
