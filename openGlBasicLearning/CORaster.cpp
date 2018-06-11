
#include "stdafx.h"
#include "CORaster.h"

using namespace std;
CORaster::CORaster(int myWidth, int myHeight, COColor myColor)
	:pixelArray( nullptr )
	//initialize null pointer
{
	if (checkSize(myWidth, myHeight))
	{
		width = myWidth;
		height = myHeight;
		makePixels(width, height);

		fillRectangle(myColor);
	}
}

CORaster::CORaster( int myWidth = 0, int myHeight = 0, COColor mypixelArray[] = nullptr)
	:pixelArray(nullptr)
{
	if (checkSize(myWidth, myHeight))
	{
		width = myWidth;
		height = myHeight;

		makePixels(width , height);
		setPixels(width , height , mypixelArray);
	}
}

CORaster::~CORaster()
{
	freePPixels();
}

void CORaster::makePixels(int myWidth, int myHeight)
{
	//这里使用内存连续空间的分配方法，pixelArray每个像素在内存上是连续的空间
	freePPixels();
	if (checkSize(myWidth, myHeight))
	{
		width = myWidth;
		height = myHeight;

		pixelArray = (COColor **)malloc(sizeof(COColor*) * height);
		pixelArray[0] = (COColor*)malloc(sizeof(COColor) * width*height);
		for (int i = 1; i < height; i++)
		{
			pixelArray[i] = pixelArray[i-1] + width;
		}
	}
}


void CORaster::setPixels( int myWidth, int myHeight , COColor setPixels[] )
{
	if (this->checkSize(myWidth, myHeight))
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				pixelArray[j][i] = setPixels[j*width + i];
			}
		}
	}
}

void CORaster::freePPixels()
{
	if (!(pixelArray == nullptr))
	{
		if (!(pixelArray[0] == nullptr))
		{
			free(pixelArray[0]);
			free(pixelArray);
		}
	}
}

bool CORaster::checkSize(int myWidth, int myHeight)
{
	bool success = false;
	if (myWidth > 0 && myHeight > 0)
	{

		success = true;

	}
	return (success);
}

int CORaster::getWidth()
{
	return(width);
}
int CORaster::getHeight()
{
	return(height);
}

bool CORaster::saveToFile(char *_path)
{
	//用法: 
	//char myPath[]= "d:/test.ppm";
	//myRaster.saveToFile(myPath);

	ofstream ppmFile;
	ppmFile.open(/*"d:/test.ppm"*/_path, ios::out);
	if (ppmFile.is_open())
	{
		string myStr;
		ppmFile << "P3\n";
		myStr = to_string(width) + " " + to_string(height) + " " + to_string(colourDepth) + "\n";
		ppmFile << myStr;
		myStr = "";
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				COColor thisPixel = pixelArray[j][i];
				TCOChannel red   = thisPixel.r ;
				TCOChannel green = thisPixel.g ;
				TCOChannel blue  = thisPixel.b ;

				ppmFile << int(red);
				ppmFile << " ";
				ppmFile << int(green);
				ppmFile << " ";
				ppmFile << int(blue);
				ppmFile << " ";
			}
			ppmFile << "\n";
		}
		ppmFile.close();
	}
	return (true);
}


void CORaster::print()
{
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i <width; i++)
		{
			cout << "(" << hex << ((int)(pixelArray[j][i]).a) << "," << (int)pixelArray[j][i].r << ","\
				<< (int)pixelArray[j][i].g << "," << (int)pixelArray[j][i].b << ")";
		}
		cout << endl;
	}
}

void CORaster::fillRectangle(COColor myFillColor)
{
	//把fill整个raster变成fill矩形
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			pixelArray[j][i] = myFillColor;
		}
	}
}

void CORaster::drawTriangle(COTriangle myTriangle, int mode)
{
	//mode = 0 : solid color
	//mode = 1 : blend 
	//todo: 因为triangle转为COVector 需要重新写这里
	/*
	COColor fillColor = COCOLOR_GREEN;
	COColor blendColor ;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			COVector2 curPixel = Vector::makeCOVector2(x, y);

			COVector3 myV3 = Vector::makeCOVector3(0.0f, 0.0f, 0.0f);
			bool inTriangle = Triangle :: getBarycentric(myTriangle, curPixel, &myV3);

			COColor _colorA = Color::multiply(COCOLOR_GREEN, myV3.x);
			COColor _colorB = Color::multiply(COCOLOR_RED, myV3.y);
			COColor _colorC = Color::multiply(COCOLOR_BLUE, myV3.z);
			blendColor = Color::add(_colorA, _colorB);
			blendColor = Color::add(blendColor, _colorC);

			if (Triangle ::isInTriangle (myTriangle, curPixel))
			{
				//check if the coordinat is in the tri
				pixelArray[y][x] = mode == 0 ? fillColor : blendColor;
			}
		}
	}*/
}