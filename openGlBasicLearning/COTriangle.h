#pragma once
#include "COVector.h"

struct COTriangle
{
	COVector2 * vertexArray;
};

class Triangle
{
public:
	static COTriangle makeTriangle ( COVector2* );
	static bool isTriangle ( COVector2* );
	static bool isInTriangle(COTriangle , COVector2);
	static void print(COTriangle);
};

//--------------------------------- old need delete -------------------------------
class TCOVector2;
class TCOTriangle
{
public:
	TCOVector2 * vertexArray;
	TCOTriangle(TCOVector2*);
	void print();
	static bool isTriangle(TCOVector2*);
	bool isInTriangle(TCOVector2*);

};
