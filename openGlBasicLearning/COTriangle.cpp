#include "stdafx.h"
#include "COTriangle.h"
COTriangle::COTriangle(COVector2* _vArray)
{
	if (COTriangle::isTriangle(_vArray))
	{
		cout << "is triangle" << endl;
		this->vertexArray = _vArray;
	}
}

void COTriangle::print()
{
	if (this->vertexArray != NULL)
	{
		cout << "[";
		this->vertexArray[0].print();
		cout << ", ";
		this->vertexArray[1].print();
		cout << ", ";
		this->vertexArray[2].print();
		cout << "]" << endl;
	}
}

bool COTriangle::isTriangle(COVector2* _vArray)
{
	bool result = true;
	if (_vArray[0]== _vArray[1]|| _vArray[0] == _vArray[2]||_vArray[1]== _vArray[2])
	{
		result = false;
	}
	return (result);
}

bool COTriangle::isInTriangle(COVector2 _TestVector)
{
	bool result = false;
	if (this->vertexArray == NULL){	}
	else
	{
		COVector2 v = _TestVector;
		COVector2 v1 = this->vertexArray[0];
		COVector2 v2 = this->vertexArray[1];
		COVector2 v3 = this->vertexArray[2];
		float devideBy = (float)(((v2.y - v3.y)*(v1.x - v3.x) + (v3.x - v2.x)*(v1.y - v3.y)));
		float lam1 = (float)(((v2.y-v3.y)*(v.x-v3.x) +(v3.x-v2.x)*(v.y-v3.y))/devideBy);
		float lam2 = (float)(((v3.y-v1.y)*(v.x-v3.x)+(v1.x-v3.x)*(v.y-v3.y)) /devideBy);

		if ((lam1 > 0 && lam1 < 1) && (lam2 > 0 && lam2 < 1))
		{
			result = true;
		}
	}
	if (result)
	{
		cout << "IN the triangle" << endl;
	}
	else
	{
		cout << "OUT the triangle" << endl;
	}
	return(result);
}