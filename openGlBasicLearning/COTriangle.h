#pragma once
#include "COVector.h"
class COVector2;
class COTriangle
{
public:
	COVector2* vertexArray = NULL;
	COTriangle(COVector2*);
	void print();
	static bool isTriangle(COVector2*);
	bool isInTriangle(COVector2);
};
