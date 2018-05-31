#pragma once
#include "COVector.h"

struct COTriangle
{
	COVector3 vertexA;
	COVector3 vertexB;
	COVector3 vertexC;
};

class Triangle
{
public:
	static COTriangle makeTriangle (COVector3, COVector3, COVector3);
	static bool isTriangle (COVector3, COVector3, COVector3);
	static bool isInTriangle(COTriangle , COVector2);
	static void print(COTriangle);
	static bool getBarycentric2D(COTriangle, COVector2 myTestVector, COVector3*);
};