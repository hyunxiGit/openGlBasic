// openGlBasicLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "COVector.h"
#include "CORaster.h"
#include "COTriangle.h"
#include "RasterDraw.h"
#include "COColor.h"


//void RasterSaveToPPM(Raster);
int main()
{
	COColor myColorArray[9] = { COCOLOR_BLACK , COCOLOR_WHITE , COCOLOR_BLACK,\
								COCOLOR_RED   , COCOLOR_GREEN , COCOLOR_BLUE, \
								COCOLOR_CLEAR , COCOLOR_WHITE , COCOLOR_BLACK };
	
	CORaster myRaster(3, 3, myColorArray);
	/*for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "(" << j << "," << i << "),";
			cout <<"(" <<hex<<((int)(myRaster.pixelArray[j][i]).a)<<"," <<(int)myRaster.pixelArray[j][i].r << ","\
				<< (int)myRaster.pixelArray[j][i].g << ","<< (int)myRaster.pixelArray[j][i].b << ")" ;
		}
		cout << endl;
	}*/
	myRaster.print();

	cout << "width : " << myRaster.getWidth()<<endl;
	cout << "height : " << myRaster.getHeight()<<endl;
	char myPath[]= "d:/test.ppm";
	myRaster.saveToFile(myPath);
	system("pause");

	/*
	COVector2 tri[3] = { COVector2(15.0f, 5.0f), COVector2(5.0f, 15.0f), COVector2(5.0f, 5.0f)};
	COTriangle myTri(tri);

	COVector2 a(0.1, 1.1);
	COVector2 *vptr = &a;
	
	int _width = 32;
	int _height = 32;

	CORaster ad(_width, _height);

	RasterDraw drawer;
	drawer.drawTriangle(&ad, &myTri);

	char d[] = "d:/test.ppm";
	ad.saveToFile(d);
    */
	return 0;
	
}


