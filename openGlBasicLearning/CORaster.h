#pragma once
#include "stdafx.h"
#include "COColor.h"

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

	/*todo_________________________________
	static void drawTriangle(COTriangle*);
	//order : from left corner , check trangle
	
	_________________________________todo*/
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