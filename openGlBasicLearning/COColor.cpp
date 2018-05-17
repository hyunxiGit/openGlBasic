#include "stdafx.h"
# include "COColor.h"
COColor::COColor(COColorByte myColor)
{
	//seperate channel to ByteChannel
	colorByte = myColor;
	initPtr();
}

COColor::COColor(COChanelByte* myChannelArray)
{
	int len;
	GET_ARRAY_LEN(myChannelArray, len);
	if (len != 4)
	{
		return;
	}
	
	COColorByte tempA = myChannelArray[0] << 24 & 0xff000000;
	COColorByte tempR = myChannelArray[1] << 16 & 0x00ff0000;
	COColorByte tempG = myChannelArray[2] << 8  & 0x0000ff00;
	COColorByte tempB = myChannelArray[3]       & 0x000000ff;

	colorByte = tempA + tempR + tempG + tempB;

	initPtr();
}

void COColor :: initPtr()
{
	colorptr = &colorByte;
	bPtr = (COChanelByte*)(colorptr);
	gPtr = bPtr + 1;
	rPtr = bPtr + 2;
	aPtr = bPtr + 3;
}

float* COColor ::COColorToFloat()
{
	//todo ���ﻹ��̫�ԣ�����������û�г����ԵĽ��
	float myFloatColor[4];

	if (aPtr != nullptr && rPtr != nullptr && gPtr != nullptr && bPtr != nullptr)
	{
		myFloatColor[0] = *aPtr / 255.0;
		myFloatColor[1] = *rPtr / 255.0;
		myFloatColor[2] = *gPtr / 255.0;
		myFloatColor[3] = *bPtr / 255.0;
	}
	
	return (myFloatColor);
}

COColorByte COColor::floatToByte(float * myFloatColor)
{
	COColorByte myByteColor = 0x0;
	
	//��ʼ�����ﻹ�е�����
	
	if (myFloatColor != nullptr)
	{
		int len;
		GET_ARRAY_LEN(myFloatColor, len);
		if (len != 4)
		{
			cout << "length must be 4 for color component" << endl;
			//todo: ������Ҫ����ô����������Ϸ�
			return (myByteColor);
		}

		//ȡ�������е�ÿ�����ݣ�ת��byte�� ���� COColorByte
		COChanelByte a = (int)(255 * myFloatColor[0]);
		COChanelByte r = (int)(255 * myFloatColor[1]);
		COChanelByte g = (int)(255 * myFloatColor[2]);
		COChanelByte b = (int)(255 * myFloatColor[3]);

		COColorByte tempA = a << 24 & 0xff000000;
		COColorByte tempR = r << 16 & 0x00ff0000;
		COColorByte tempG = g << 8 & 0x0000ff00;
		COColorByte tempB = b & 0x000000ff;

		myByteColor = tempA + tempR + tempG + tempB;
		return (myByteColor);
	}
}

COColor COColor::operator+(COColor myColor)
{
	return myColor;
}

COColor COColor::operator*(float myScaler)
{
	return colorByte;
}

void COColor :: print(short mode = 0)
{
	switch (mode)
	{
	case 0:
		//output :  0xFFFFFF (1,1,1,1)
		cout << " 0x" << hex << colorByte << " ";
		//todo : ����д���flolat�� ��Ϊfloat��Ա��������
		//cout << "(" << setprecision(2) <<aFloat << " , " << rFloat << " , " << gFloat << " , " << bFloat << " ) " << endl;
		break;

	case 1:
		//output :  0xFFFFFF (255,255,255,255)
		cout << " 0x" << hex << colorByte << " ";
		cout << "(" << oct << (int)(*aPtr) << " , " << (int)(*rPtr) << " , " << (int)(*gPtr) << " , " << (int)(*bPtr) << " )";
		break;

	case 2:
		//output : 0xFFFFFF <Color Address> <Achannel Address, Rchannel Address, Gchannel Address, Bchannel Address,>
		cout << "0x" << hex << colorByte << " ";
		cout << "<" << static_cast<const void *>(colorptr) << "> ";
		cout << "<" << static_cast<const void *>(aPtr) <<" , " << static_cast<const void *>(rPtr) << " , " << static_cast<const void *>(gPtr) << " , " << static_cast<const void *>(bPtr) << ">" << endl;
		break;

	default:
		break;
	};
}