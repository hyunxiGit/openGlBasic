#pragma once
#ifndef RASTER_H
#define RASTER_H
#include "stdafx.h"

typedef uint32_t COColor;
typedef uint8_t COChannel;

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

	COColor **pPixels = NULL;

	Raster(int, int);
	Raster(COColor[], int, int);
	~Raster();

	void setPixels(COColor[], int, int);
	bool checkSize(int, int);
	void print();
private:
	void freePPixels();
	void makePixels(int, int);
};
#endif