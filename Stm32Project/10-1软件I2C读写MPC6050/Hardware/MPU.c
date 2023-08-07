#include "stm32f10x.h"                  // Device header
#include "MYI2C.h"
#include "MPU6050Reg.h"
#include "MPU.h"

#define MPUAddress  0xD0



void MPU_WriteReg(uint8_t RegAddress, uint8_t data)
{
	MYI2C_Start();
	MYI2C_SendByte(MPUAddress);
	MYI2C_ReceiveAck();
	MYI2C_SendByte(RegAddress);
	MYI2C_ReceiveAck();
	MYI2C_SendByte(data);
	MYI2C_ReceiveAck();
	MYI2C_Stop();
}


uint8_t MPU_ReadReg(uint8_t RegAddress)
{
	uint8_t RegByte;
	
	MYI2C_Start();
	MYI2C_SendByte(MPUAddress);
	MYI2C_ReceiveAck();
	MYI2C_SendByte(RegAddress);
	MYI2C_ReceiveAck();
	
	MYI2C_Start();
	MYI2C_SendByte(MPUAddress | 0X01);
	MYI2C_ReceiveAck();
	RegByte = MYI2C_ReceiveByte();
	MYI2C_SendAck(1);
	MYI2C_Stop();
	return RegByte;
}

void MPU_Init(void)
{
	MYI2C_Init();
	MPU_WriteReg(MPU6050_PWR_MGMT_1, 0X01);
	MPU_WriteReg(MPU6050_PWR_MGMT_2, 0X00);
	MPU_WriteReg(MPU6050_ACCEL_CONFIG, 0X09);
	MPU_WriteReg(MPU6050_CONFIG,0X06);
	MPU_WriteReg(MPU6050_GYRO_CONFIG, 0X18);
	MPU_WriteReg(MPU6050_ACCEL_CONFIG,0X18);	
}

uint8_t MPU_GetID(void)
{
	return MPU_ReadReg(MPU6050_WHO_AM_I);
}

void MPU_GetData(MPU6050_GetValue *Data)
{
	uint8_t DataH, DataL;
	DataH = MPU_ReadReg(MPU6050_ACCEL_XOUT_H);
	DataL = MPU_ReadReg(MPU6050_ACCEL_XOUT_L);
	Data->AccX = (DataH << 8) | DataL;
	
	DataH = MPU_ReadReg(MPU6050_ACCEL_YOUT_H);
	DataL = MPU_ReadReg(MPU6050_ACCEL_YOUT_L);
	Data->AccY = (DataH << 8) | DataL;
	
	DataH = MPU_ReadReg(MPU6050_ACCEL_ZOUT_H);
	DataL = MPU_ReadReg(MPU6050_ACCEL_ZOUT_L);
	Data->AccZ = (DataH << 8) | DataL;
	
	DataH = MPU_ReadReg(MPU6050_GYRO_XOUT_H);
	DataL = MPU_ReadReg(MPU6050_GYRO_XOUT_L);
	Data->GyroX = (DataH << 8) | DataL;
	                                 
	DataH = MPU_ReadReg(MPU6050_GYRO_YOUT_H);
	DataL = MPU_ReadReg(MPU6050_GYRO_YOUT_L);
	Data->GyroY = (DataH << 8) | DataL;
	                                 
	DataH = MPU_ReadReg(MPU6050_GYRO_ZOUT_H);
	DataL = MPU_ReadReg(MPU6050_GYRO_ZOUT_L);
	Data->GyroZ = (DataH << 8) | DataL;
}
