#ifndef __MYSPI_H
#define __MYSPI_H


uint8_t MYSPI_SwapByte(uint8_t SendByte);
void MYSPI_Stop(void);
void MYSPI_Start(void);
void MYSPI_Init(void);
void Write7219(unsigned char addr, unsigned char dat);

#endif
