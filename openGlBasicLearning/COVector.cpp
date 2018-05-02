#include "stdafx.h"
#include "COVector.h"

void coTestFunction()
{
	printf("this is coTestFunction");
}

COVector2::COVector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

COVector2 COVector2::operator+ (COVector2 _a)
{
	COVector2 resultVector(x + _a.x, y + _a.y);
	return(resultVector);
}

COVector2 COVector2::operator* (float _a)
{
	COVector2 resultVector((float)x * _a, (float)y * _a);
	return(resultVector);
}

bool COVector2 :: operator== (COVector2 _a)
{
	bool result = false;
	if (x == _a.x && y == _a.y)
	{
		result = true;
	}
	return (result);
}

void COVector2::print()
{
	cout << "(";
	cout << x;
	cout << ",";
	cout << y;
	cout << ")";
}


