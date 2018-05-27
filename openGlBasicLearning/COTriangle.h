#pragma once
#include "COVector.h"

struct COTriangle
{
	COVector2 vertexA;
	COVector2 vertexB;
	COVector2 vertexC;
};

class Triangle
{
public:
	static COTriangle makeTriangle (COVector2, COVector2, COVector2);
	static bool isTriangle (COVector2, COVector2, COVector2);
	static bool isInTriangle(COTriangle , COVector2);
	static void print(COTriangle);
	static bool getBarycentric(COTriangle, COVector2 myTestVector, COVector3*);
};