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

const COColor COCOLOR_BLACK = Color::makeCOColor((COChanelByte)255, (COChanelByte)0, (COChanelByte)0, (COChanelByte)0);
const COColor COCOLOR_WHITE = Color::makeCOColor((COChanelByte)255, (COChanelByte)255, (COChanelByte)255, (COChanelByte)255);
const COColor COCOLOR_RED = Color::makeCOColor((COChanelByte)255, (COChanelByte)255, (COChanelByte)0, (COChanelByte)0);
const COColor COCOLOR_GREEN = Color::makeCOColor((COChanelByte)255, (COChanelByte)0, (COChanelByte)255, (COChanelByte)0);
const COColor COCOLOR_BLUE = Color::makeCOColor((COChanelByte)255, (COChanelByte)0, (COChanelByte)0, (COChanelByte)255);
const COColor COCOLOR_CLEAR = Color::makeCOColor((COChanelByte)0, (COChanelByte)0, (COChanelByte)0, (COChanelByte)0);