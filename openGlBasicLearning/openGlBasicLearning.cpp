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

	COVector3 myTV = Vector::makeCOVector3(1.0f, 0.0f, 0.0f);
	cout << "before transfer : ";
	Vector::print(myTV);
	COVector3 myAV = Vector::makeCOVector3(1, 1, 0);
	
	myTV = Matrix::rotateA(myAV, myTV, pi);
	cout << "after transfer 2 : ";
	Vector::print(myTV);

	system("pause");

	return 0;
	
}


