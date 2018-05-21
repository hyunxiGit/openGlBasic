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
	//这个构造函数用的时候需要保证数组长度为4，顺序为ARGB
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