// openGlBasicLearning.cpp : Defines the entry point for the console application.
//




#include "stdafx.h"
#include "COVector.h"

using namespace std;

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
	Raster(COColor[],int,int);
	~Raster();

	void setPixels(COColor[], int, int);
	bool checkSize(int,int);
	void printPPixel();
private :
	void freePPixels();
	void makePixels(int, int);
};

Raster::Raster(int myWidth, int myHeight)
{
	if (this->checkSize(myWidth, myHeight))
	{
		this->width = myWidth;
		this->height = myHeight;
		this->arraySize = myWidth * myHeight;
		this->makePixels(this->width, this->height);
	}
}

Raster::Raster(COColor pixelArray[],int myWidth =0, int myHeight =0)
{
	
	if (this->checkSize(myWidth,myHeight))
	{
		this->width = myWidth;
		this->height = myHeight;
		this->arraySize = myWidth * myHeight;

		this->makePixels(this->width, this->height);
		this->setPixels(pixelArray, this->width, this->height);
	}	
}

Raster::~Raster()
{
	freePPixels();
}

void Raster::makePixels(int myWidth, int myHeight)
{
	this->freePPixels();
	if (this->checkSize(myWidth, myHeight))
	{
		this->width = myWidth;
		this->height = myHeight;
		this->arraySize = this->width * this->height;

		this->pPixels = (COColor**)malloc(sizeof(COColor*)*this->height);
		for (int i = 0; i < this->height; i++)
		{
			*(pPixels + i) = (COColor*)malloc(sizeof(int*)*this->width);
		}

		//initialize the pixel tobe defaultValue
		for (int j = 0; j < this->height; j++)
		{
			for (int i = 0; i < this->width; i++)
			{
				this->pPixels[j][i] = this->DEFAULT_VALUE;
			}
		}
	}
}


void Raster::setPixels(COColor setPixels[], int myWidth, int myHeight)
{
	if (this->checkSize(myWidth, myHeight))
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{
				pPixels[j][i] = setPixels[j*width + i];
			}
		}
	}
}

void Raster::freePPixels()
{
	if (!(pPixels == NULL))
	{
		for (int i = 0; i < this->height; i++)
		{

			free(*(pPixels + i));

		}
	}
}

bool Raster::checkSize(int myWidth, int myHeight)
{
	bool success = false;
	if (myWidth > 0 && myHeight > 0)
	{

		success = true;
		
	}
	return (success);
}

void Raster::printPPixel()
{
	for (int j = 0; j < this->height; j++)
	{
		for (int i = 0; i <this->width; i++)
		{
			//cout << this->pPixels[j][i];
			printf("0x%06x\n", this->pPixels[j][i]);
		}
		cout << endl;
	}
}


void RasterSaveToPPM(Raster);

int main()
{
	
	COVector2 vd(3.6, 5.6);
	//Raster ad(3,4);
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
	ad.printPPixel();
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

