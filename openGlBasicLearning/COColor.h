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

	uint8_t a = 0;
	double b = 0.132358703512086750812643;
	uint8_t c = 5;

	

	COColor(COColorByte);
	COColor(const COColor&);
	//Õâ¸ö¹¹Ôìº¯ÊýÓÃµÄÊ±ºòÐèÒª±£Ö¤Êý×é³¤¶ÈÎª4£¬Ë³ÐòÎªARGB
	//尝试一下使用中文注释
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