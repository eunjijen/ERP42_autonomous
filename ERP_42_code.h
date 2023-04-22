//#pragma once
#include <stdio.h>
#include <windows.h>

typedef struct ReceiveDatal {

	int AutoManualVar;
	int EStopVar;
	int GearVar;
	int SpeedVar;
	int SteeringVar;
	int BreakVar;

	INT32 EncoderVar;

}ReceiveData;

ReceiveData Rec;

HANDLE ERP42ComDevId;

char szPort[15] = "";
unsigned char tx_d[14] = { 0, };
unsigned char Sendbuf[14] = { 0x53,0x54,0x58,1,0,1,0,0,0,0,0,0,0x0D,0x0A };
unsigned char rx_d[18] = { 0, };
unsigned char rx_d_sensor1[18] = { 0, };
unsigned int speed = 0;
unsigned char connectstate = 0;
DWORD dwByte;


void delay(int ms)
{
	Sleep(ms);
}

void Open(char *szport)
{
	if (connectstate == 0)
	{
		ERP42ComDevId = CreateFile(
			szport,
			GENERIC_READ | GENERIC_WRITE,
			0,
			NULL,
			OPEN_EXISTING,
			0,
			NULL);

		COMMTIMEOUTS CommTimeOuts;
		GetCommTimeouts(ERP42ComDevId, &CommTimeOuts);
		CommTimeOuts.ReadIntervalTimeout = 0;
		CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
		CommTimeOuts.ReadTotalTimeoutConstant = 0;
		CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
		CommTimeOuts.WriteTotalTimeoutConstant = 0;
		SetCommTimeouts(ERP42ComDevId, &CommTimeOuts);

		DCB dcb;
		GetCommState(ERP42ComDevId, &dcb);
		dcb.BaudRate = CBR_115200;
		dcb.ByteSize = 8;
		dcb.Parity = NOPARITY;
		dcb.StopBits = 1;
		dcb.fBinary = TRUE;
		dcb.fParity = FALSE;

		SetCommState(ERP42ComDevId, &dcb);
		Sleep(1000);
		connectstate = 1;
	}
}

int Alive(int aliveValue)
{
	Sendbuf[11] = (byte)aliveValue;
	aliveValue = aliveValue + 1;

	return aliveValue;
}

void Close()
{
	if (connectstate == 1)
	{
		Sleep(1000);
		CloseHandle(ERP42ComDevId);
		connectstate = 0;
	}
}

void SendData(unsigned char *Sendbuf)
{
	tx_d[0] = 0x53;				//S
	tx_d[1] = 0x54;				//T
	tx_d[2] = 0x58;				//X
	tx_d[3] = Sendbuf[3];		//AorM
	tx_d[4] = Sendbuf[4];		//E-STOP
	tx_d[5] = Sendbuf[5];		//GEAR
	tx_d[6] = Sendbuf[6];		//SPEED0
	tx_d[7] = Sendbuf[7];		//SPEED1
	tx_d[8] = Sendbuf[8];		//STEER0
	tx_d[9] = Sendbuf[9];		//STEER1
	tx_d[10] = Sendbuf[10];		//BRAKE
	tx_d[11] = Sendbuf[11];		//ALIVE
	tx_d[12] = 0x0D;			//ETX0
	tx_d[13] = 0x0A;			//ETX1

	PurgeComm(ERP42ComDevId, PURGE_TXCLEAR);
	WriteFile(ERP42ComDevId, tx_d, 14, &dwByte, 0);
}

void Speed(int speedValue)
{
	Sendbuf[6] = 0;
	Sendbuf[7] = 0;
	Sendbuf[6] = (byte)(speedValue / 256);
	Sendbuf[7] = (byte)(speedValue % 256);
	//SendData(Sendbuf);
}

void Steering(int steeringValue)
{
	Sendbuf[8] = 0;
	Sendbuf[9] = 0;
	if (steeringValue < 0) {
		steeringValue -= 256;
		if (steeringValue % 256 == 0)
			steeringValue += 256;
	}
	Sendbuf[8] = (byte)(steeringValue / 256);
	Sendbuf[9] = (byte)(steeringValue % 256);
	//SendData(Sendbuf);
}

void AutoManual(int AutoManualValue)
{
	Sendbuf[3] = (byte)(AutoManualValue);
	//SendData(Sendbuf);
}

void EStop(int EStopValue)
{
	Sendbuf[4] = (byte)EStopValue;
	//SendData(Sendbuf);
}

void Gear(int GearValue)
{
	Sendbuf[5] = (byte)GearValue;
	//SendData(Sendbuf);
}

void Brake(int BreakValue)
{
	Sendbuf[10] = (byte)BreakValue;
	//SendData(Sendbuf);
}

void checkdata()
{
	if ((rx_d[0] == 0x53) && (rx_d[1] == 0x54) && (rx_d[2] == 0x58) && (rx_d[16] == 0x0D) && (rx_d[17] == 0x0A)) {
		rx_d_sensor1[3] = rx_d[3];
		rx_d_sensor1[4] = rx_d[4];
		rx_d_sensor1[5] = rx_d[5];
		rx_d_sensor1[6] = rx_d[6];
		rx_d_sensor1[7] = rx_d[7];
		rx_d_sensor1[8] = rx_d[8];
		rx_d_sensor1[9] = rx_d[9];
		rx_d_sensor1[10] = rx_d[10];
		rx_d_sensor1[11] = rx_d[11];
		rx_d_sensor1[12] = rx_d[12];
		rx_d_sensor1[13] = rx_d[13];
		rx_d_sensor1[14] = rx_d[14];
	}
}

ReceiveData RecData()
{
	ReceiveData ReceiveDatal;
	//SendData(Sendbuf);

	ReadFile(ERP42ComDevId, rx_d, 18, &dwByte, 0);
	checkdata();

	PurgeComm(ERP42ComDevId, PURGE_RXCLEAR);

	ReceiveDatal.AutoManualVar = rx_d_sensor1[3];
	ReceiveDatal.EStopVar = rx_d_sensor1[4];
	ReceiveDatal.GearVar = rx_d_sensor1[5];
	ReceiveDatal.SpeedVar = rx_d_sensor1[7] * 256 + rx_d_sensor1[6];
	ReceiveDatal.SteeringVar = rx_d_sensor1[9] * 256 + rx_d_sensor1[8];
	ReceiveDatal.BreakVar = rx_d_sensor1[10];
	ReceiveDatal.EncoderVar = (rx_d_sensor1[14] * 256 + rx_d_sensor1[13]) * 256 + (rx_d_sensor1[12] * 256 + rx_d_sensor1[11]);

	return ReceiveDatal;
}

