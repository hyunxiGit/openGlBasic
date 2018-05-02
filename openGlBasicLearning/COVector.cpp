#include "stdafx.h"
#include "COVector.h"

void coTestFunction()
{
	printf("this is coTestFunction");
}

COVector2::COVector2(float _x, float _y)
{
	this->x = _x;
	this->y = _y;
}

COVector2 COVector2::operator+ (COVector2 _a)
{
	COVector2 resultVector(this->x+_a.x, this->y + _a.y);
	return(resultVector);
}

COVector2 COVector2::operator* (float _a)
{
	COVector2 resultVector((float)this->x*_a, (float)this->y*_a);
	return(resultVector);
}

bool COVector2 :: operator== (COVector2 _a)
{
	bool result = false;
	if (this->x == _a.x && this->y == _a.y)
	{
		result = true;
	}
	return (result);
}

void COVector2::print()
{
	cout << "(";
	cout << this->x;
	cout << ",";
	cout << this->y;
	cout << ")";
}


