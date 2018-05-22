#pragma once
#include "stdafx.h"

typedef uint32_t COColorByte;
typedef uint8_t  COChanelByte;
struct COColor
{
	COChanelByte a;
	COChanelByte r;
	COChanelByte g;
	COChanelByte b;
};

class Color
{
public:
	//new
	static COColor makeCOColor ( COChanelByte, COChanelByte, COChanelByte, COChanelByte );
	static COColor makeCOColor ( float, float, float, float );
	
	static COColorByte getIntColor(COColor);
	
	static float getFloat(COChanelByte);
	
	static COChanelByte getByte(float);

	static COColor add      ( COColor , COColor);
	static COColor multiply ( COColor , float);
};