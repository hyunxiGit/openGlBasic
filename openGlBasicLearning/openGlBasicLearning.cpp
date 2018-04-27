// openGlBasicLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdint.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef uint32_t COColor;
typedef uint8_t COChannel;
class Raster 
{
public:
	const int MAX_WIDTH = 1280;
	const int MAX_HEIGHT = 720;
	
	int width = 1;
	int height = 1;
	int colourDepth = 255;

	COColor **pPixels;

	Raster(int, int);
	Raster(COColor[],int,int);
	~Raster();
};

Raster::Raster(int myWidth, int myHeight)
{

	if (myWidth > 0 && myWidth < MAX_WIDTH)
	{
		this->width = myWidth;
	}
	if (myHeight > 0 && myHeight < MAX_HEIGHT)
	{
		this->height = myHeight;
	}

	pPixels = (COColor**)malloc(sizeof(COColor*)*height);
	for (int i = 0; i < height; i++)
	{
		*(pPixels + i) = (COColor*)malloc(sizeof(int*)*width);
	}

	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			pPixels[j][i] = 0xffffff;
		}
	}
}

Raster::Raster(COColor pixelArray[],int myWidth, int myHeight)
{
	if (myWidth>0&& myHeight>0 &&sizeof(pixelArray) == myWidth* myHeight)
	{

	}
}

Raster::~Raster()
{
	for (int i = 0; i < this->height; i++)
	{
		free(*(pPixels +i));
	}
}


void RasterSaveToPPM(Raster);
int main()
{
	Raster ad(3,4);

	
	//RasterSaveToPPM(ad);
    return 0;
}

void RasterSaveToPPM(Raster ras/*, char* path*/)
{
	ofstream ppmFile;
	ppmFile.open("d:/test.ppm", ios::out);
	if (ppmFile.is_open())
	{
		string myStr;
		ppmFile << "P3\n";
		myStr = to_string(ras.width) + " " + to_string(ras.height)+" "+ to_string(ras.colourDepth)+"\n";
		ppmFile << myStr;
		myStr = "";
		for (int j=0; j < ras.height; j++)
		{
			for (int i=0; i < ras.width; i++)
			{
				COColor thisPixel = ras.pPixels[j][i];

				//printf("0x%x\n", thisPixel);
				COChannel red = (ras.pPixels[j][i] & 0xff0000)>>16;
				COChannel green = (ras.pPixels[j][i] & 0x00ff00)>>8;
				COChannel blue = ras.pPixels[j][i] & 0x0000ff;
				
				ppmFile << int(red);
				ppmFile << " ";
				ppmFile << int(green);
				ppmFile << " ";
				ppmFile << int(blue);
				ppmFile << " ";

			}
			ppmFile <<"\n";
		}
		ppmFile.close();
	}
}

