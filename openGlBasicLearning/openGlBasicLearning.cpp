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
	
	CORaster myRaster(100, 100, COCOLOR_BLACK);

	COVector2 myV1 = Vector::makeCOVector2(0.0f, 0.0f);
	COVector2 myV2 = Vector::makeCOVector2(50.0f, 0.0f);
	COVector2 myV3 = Vector::makeCOVector2(0.0f, 50.0f);

	COTriangle myTri = Triangle::makeTriangle(myV1, myV2, myV3);

	myRaster.drawTriangle(myTri);

	/*cout << "width : " << myRaster.getWidth()<<endl;
	cout << "height : " << myRaster.getHeight()<<endl;*/
	char myPath[]= "d:/test.ppm";
	myRaster.saveToFile(myPath);
	system("pause");

	return 0;
	
}


