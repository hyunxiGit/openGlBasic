#pragma once
#include "stdafx.h"


class CORaster
{
public:
	const int MAX_WIDTH = 1280;
	const int MAX_HEIGHT = 720;
	const TCOColor DEFAULT_VALUE = 0x000002;

	int width = 1;
	int height = 1;
	int arraySize = 1;
	int colourDepth = 255;

	TCOColor **pPixels;

	//make Raster in default colour
	CORaster(int, int);
	//make Raster using COColorArray
	CORaster(TCOColor[], int, int);
	~CORaster();

	void setPixels(TCOColor[], int, int);
	bool checkSize(int, int);
	bool saveToFile(char*);
	void print();
private:
	void freePPixels();
	void makePixels(int, int);
};