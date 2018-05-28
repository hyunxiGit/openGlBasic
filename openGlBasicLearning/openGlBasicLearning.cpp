// openGlBasicLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "COVector.h"
#include "CORaster.h"
#include "COTriangle.h"
#include "RasterDraw.h"
#include "COColor.h"
#include "COMatrix.h"


//void RasterSaveToPPM(Raster);
int main()
{
	double pi = 3.1415926535897932 ; 
	COVector2 myTargetV = Vector::makeCOVector2(1, 1);
	COVector2 myresultV = Matrix::scale (myTargetV, 0.5 , 3);
	cout << "myresultV.x : " << myresultV.x << endl;
	cout << "myresultV.y : " << myresultV.y << endl;
	CORaster myRaster(100, 100, COCOLOR_BLACK);

	COVector2 myV1 = Vector::makeCOVector2(10.0f, 10.0f);
	COVector2 myV2 = Vector::makeCOVector2(80.0f, 0.0f);
	COVector2 myV3 = Vector::makeCOVector2(0.0f, 70.0f);

	COTriangle myTri = Triangle::makeTriangle(myV1, myV2, myV3);

	myRaster.drawTriangle(myTri, 0);

	/*cout << "width : " << myRaster.getWidth()<<endl;
	cout << "height : " << myRaster.getHeight()<<endl;*/
	char myPath[]= "d:/test.ppm";
	myRaster.saveToFile(myPath);


	system("pause");

	return 0;
	
}


