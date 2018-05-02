// openGlBasicLearning.cpp : Defines the entry point for the console application.
//




#include "stdafx.h"
#include "COVector.h"
#include "Raster.h"
#include "COTriangle.h";


void RasterSaveToPPM(Raster);

int main()
{
	COVector2 ptV[3] = { COVector2(0.0, 0.0) ,COVector2(5.0, 0.0) ,COVector2(0.0, 5.0) };
	COVector2 a(0.1, 1.1);
	COVector2 *vptr = &a;
	COTriangle myTri(ptV);
	myTri.print();
	myTri.isInTriangle(vptr);
	COColor myRasterArr[] =
	{ 
		0x000000, 0x000001,
		0xffffff, 0x00FF03,
		0x000003, 0x000004
	};
	
	int _width = 2;
	int _height = 3;
	int _size = sizeof(myRasterArr) / sizeof(COColor);

	//Raster ad(myRasterArr,_width, _height);
	Raster ad(_width, _height);

	ad.setPixels(myRasterArr, _width, _height);
	ad.print();
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

