#pragma once
class TCOVector2;
class COTriangle
{
public:
	TCOVector2 * vertexArray;
	COTriangle(TCOVector2*);
	void print();
	static bool isTriangle(TCOVector2*);
	bool isInTriangle(TCOVector2*);
};
