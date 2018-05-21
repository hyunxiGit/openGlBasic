#pragma once
#include "stdafx.h"

typedef uint32_t COColorByte;
typedef uint8_t  COChanelByte;
class COColor
{
public:
	
	//int Colour
	COColorByte    colorByte;
	COColorByte*   colorptr = nullptr;
	COChanelByte*  aPtr = nullptr;
	COChanelByte*  rPtr = nullptr;
	COChanelByte*  gPtr = nullptr;
	COChanelByte*  bPtr = nullptr;
	
	COColor(COColorByte);
	COColor(const COColor&);
	//������캯���õ�ʱ����Ҫ��֤���鳤��Ϊ4��˳��ΪARGB
	COColor(COChanelByte*);
	COColor(float*);

	COColor operator+ (COColor);
	COColor operator* (float);

	void COColorToFloat(float*);
	COColorByte floatToByte(float*);

	void getChannel(COChanelByte*);

	void print(short mode);
	//0 : 0xFFFFFF (1,1,1,1)
	//1 :  0xFFFFFF (255,255,255,255)
	//2 : 0xFFFFFF <Color Address> <A Address, R Address, G Address, B Address,>
private:
	void initPtr();
};