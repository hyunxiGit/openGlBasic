#pragma once
#include "stdafx.h"
#include "COColor.h"
#include "COTriangle.h"

class CORaster
{
public:
	//RASTER 数据
	COColor **pixelArray;

	//make Raster in default colour
	CORaster(int, int, COColor);
	//make Raster using COColorArray
	CORaster(int, int, COColor[]);

	~CORaster();

	void setPixels( int , int , COColor[] );

	
	void drawTriangle(COTriangle, int);
	//order : from left corner , check trangle
	//todo : current it fills the whole raster
	void fillRectangle(COColor);

	int getWidth();
	int getHeight();
	bool saveToFile(char*);
	void print();
private:
	int width = 1;
	int height = 1;
	int colourDepth = 255;

	void freePPixels();
	void makePixels(int, int);
	bool checkSize(int, int);
};