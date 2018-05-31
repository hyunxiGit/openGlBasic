#include "stdafx.h"
#include "COTriangle.h"
#include "COVector.h"

COTriangle Triangle::makeTriangle(COVector3 myA, COVector3 myB, COVector3 myC)
{
	COTriangle result;
	result.vertexA = myA;
	result.vertexB = myB;
	result.vertexC = myC;
	return (result);
}
bool Triangle::isTriangle(COVector3 myA, COVector3 myB, COVector3 myC)
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
	COVector3 myV3 = Vector ::makeCOVector3(0.0f, 0.0f, 0.0f);
	bool result = getBarycentric2D(myTriangle, myTestVector, &myV3);
	return (result);
}

bool Triangle ::getBarycentric2D(COTriangle myTriangle, COVector2 myTestVector, COVector3* myBarycentric)
{
	//这里要重新想一下怎么弄，分开2D和3D计算
	//先把三角形 z 轴干掉
	//计算barycentric
	
	int result = 0;
	COVector2 v0 = myTestVector;

	COVector2 v1 = myTriangle.vertexA;
	COVector2 v2 = myTriangle.vertexB;
	COVector2 v3 = myTriangle.vertexC;

	float fDevideBy = (float)(((v2.y - v3.y) * (v1.x - v3.x) + (v3.x - v2.x) * (v1.y - v3.y)));
	myBarycentric->x = (float)(((v2.y - v3.y) * (v0.x - v3.x) + (v3.x - v2.x) * (v0.y - v3.y)) / fDevideBy);
	myBarycentric->y = (float)(((v3.y - v1.y) * (v0.x - v3.x) + (v1.x - v3.x) * (v0.y - v3.y)) / fDevideBy);
	myBarycentric->z = 1.0f - myBarycentric->x - myBarycentric->y;

	if ((myBarycentric->x >= 0.0f && myBarycentric->x <= 1.0f) && (myBarycentric->y >= 0.0f && myBarycentric->y <= 1.0f) && (myBarycentric->z >= 0.0f && myBarycentric->z <= 1.0f))
	{
		result = 1;
	}
	return(result);
}

void Triangle::print(COTriangle myTriangle)
{
	
	cout << "[("<<myTriangle.vertexA.x<<","<< myTriangle.vertexA.y <<"," << myTriangle.vertexA.z<<") ,\
		("<<myTriangle.vertexB.x<<","<<myTriangle.vertexB.y << "," << myTriangle.vertexB.z<<"),\
		("<<myTriangle.vertexC.x<<"," << myTriangle.vertexC.y << "," <<myTriangle.vertexC.z<<")] "<< endl;
}