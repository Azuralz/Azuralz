#ifndef __MPU.h_
#define __MPU.h_

typedef struct
{
	int16_t AccX;
	int16_t AccY;
	int16_t AccZ;
	int16_t GyroX;
	int16_t GyroY;
	int16_t GyroZ;
} MPU6050_GetValue;

uint8_t MPU_ReadReg(uint8_t RegAddress);
void MPU_Init(void);
void MPU_WriteReg(uint8_t RegAddress, uint8_t data);
void MPU_GetData(MPU6050_GetValue *Data);
uint8_t MPU_GetID(void);

#endif
