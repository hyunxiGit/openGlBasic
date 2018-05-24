#include "stdafx.h"
#include "COVector.h"

void coTestFunction()
{
	printf("this is coTestFunction");
}

TCOVector2::TCOVector2(float _x, float _y)
{
	x = _x;
	y = _y;
}

TCOVector2 TCOVector2::operator+ (TCOVector2 _a)
{
	TCOVector2 resultVector(x + _a.x, y + _a.y);
	return(resultVector);
}

TCOVector2 TCOVector2::operator* (float _a)
{
	TCOVector2 resultVector((float)x * _a, (float)y * _a);
	return(resultVector);
}

bool TCOVector2 :: operator== (TCOVector2 _a)
{
	bool result = false;
	if (x == _a.x && y == _a.y)
	{
		result = true;
	}
	return (result);
}

void TCOVector2::print()
{
	cout << "(";
	cout << x;
	cout << ",";
	cout << y;
	cout << ")";
}


