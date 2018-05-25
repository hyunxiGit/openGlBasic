#include "stdafx.h"
#include "COTriangle.h"
#include "COVector.h"

COTriangle Triangle::makeTriangle(COVector2 myA, COVector2 myB, COVector2 myC)
{
	COTriangle result;
	result.vertexA = myA;
	result.vertexB = myB;
	result.vertexC = myC;
	return (result);
}
bool Triangle::isTriangle(COVector2 myA, COVector2 myB, COVector2 myC)
{
	bool result = true;
	if (Vector ::equal (myA, myB) || Vector::equal(myA, myC) || Vector::equal(myC, myB))
	{
		result = false;
	}
	return (result);
}
bool Triangle::isInTriangle(COTriangle myTriangle, COVector2 myTestVector)
{
	bool result = false;

	COVector2 v0 = myTestVector ;
	COVector2 v1 = myTriangle.vertexA;
	COVector2 v2 = myTriangle.vertexB;
	COVector2 v3 = myTriangle.vertexC;

	float fDevideBy = (float)(((v2.y - v3.y) * (v1.x - v3.x) + (v3.x - v2.x) * (v1.y - v3.y)));
	float fLam1 = (float)(((v2.y - v3.y) * (v0.x - v3.x) + (v3.x - v2.x) * (v0.y - v3.y)) / fDevideBy);
	float fLam2 = (float)(((v3.y - v1.y) * (v0.x - v3.x) + (v1.x - v3.x) * (v0.y - v3.y)) / fDevideBy);
	float fLam3 = 1.0f - fLam1 - fLam2;
	if ((fLam1 >= 0.0f && fLam1 <= 1.0f) && (fLam2 >= 0.0f && fLam2 <= 1.0f) && (fLam3 >= 0.0f && fLam3 <= 1.0f))
	{
		result = true;
	}
	
	return(result);
}
void Triangle::print(COTriangle myTriangle)
{
	
	cout << "[("<<myTriangle.vertexA.x<<","<< myTriangle.vertexA.y<<") ,\
		("<<myTriangle.vertexB.x<<","<< myTriangle.vertexB.y<<"),\
		("<<myTriangle.vertexC.x<<"," <<myTriangle.vertexC.y<<")] "<< endl;
}