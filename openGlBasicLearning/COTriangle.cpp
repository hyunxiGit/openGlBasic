#include "stdafx.h"
#include "COTriangle.h"
#include "COVector.h"
COTriangle::COTriangle(TCOVector2* _vArray)
	:vertexArray (nullptr) // 这里是给空指针赋值的方法，1. 因为是指针所以赋值使用 nullptr 2. 因为只有constructor 里面才能赋值所以写在constructor后面
{
	if (COTriangle::isTriangle(_vArray))
	{
		cout << "is triangle" << endl;
		vertexArray = _vArray;
	}
}

void COTriangle::print()
{
	if (vertexArray != NULL)
	{
		cout << "[";
		vertexArray[0].print();
		cout << ", ";
		vertexArray[1].print();
		cout << ", ";
		vertexArray[2].print();
		cout << "]" << endl;
	}
}

bool COTriangle::isTriangle(TCOVector2* _vArray)
{
	bool result = true;
	if (_vArray[0]== _vArray[1]|| _vArray[0] == _vArray[2]||_vArray[1]== _vArray[2])
	{
		result = false;
	}
	return (result);
}

bool COTriangle::isInTriangle(TCOVector2* _TestVector)
{
	bool result = false;
	if (vertexArray == NULL){}
	else
	{
		TCOVector2 v0 = *_TestVector;
		TCOVector2 v1 = vertexArray[0];
		TCOVector2 v2 = vertexArray[1];
		TCOVector2 v3 = vertexArray[2];
		float fDevideBy = (float)(((v2.y - v3.y) * (v1.x - v3.x) + (v3.x - v2.x) * (v1.y - v3.y)));
		float fLam1     = (float)(((v2.y - v3.y) * (v0.x - v3.x) + (v3.x - v2.x) * (v0.y - v3.y)) / fDevideBy);
		float fLam2     = (float)(((v3.y - v1.y) * (v0.x - v3.x) + (v1.x - v3.x) * (v0.y - v3.y)) / fDevideBy);
		float fLam3		= 1.0f - fLam1 - fLam2;
		if ((fLam1 >= 0.0f && fLam1 <= 1.0f) && (fLam2 >= 0.0f && fLam2 <= 1.0f) && (fLam3 >= 0.0f && fLam3 <= 1.0f))
		{
			result = true;
		}
	}
	return(result);
}