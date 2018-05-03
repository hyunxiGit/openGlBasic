#pragma once
#include "stdafx.h"


class Raster
{
public:
	const int MAX_WIDTH = 1280;
	const int MAX_HEIGHT = 720;
	const COColor DEFAULT_VALUE = 0x000002;

	int width = 1;
	int height = 1;
	int arraySize = 1;
	int colourDepth = 255;

	COColor **pPixels;

	//make Raster in default colour
	Raster(int, int);
	//make Raster using COColorArray
	Raster(COColor[], int, int);
	~Raster();

	void setPixels(COColor[], int, int);
	bool checkSize(int, int);
	bool saveToFile(char*);
	void print();
private:
	void freePPixels();
	void makePixels(int, int);
};