#pragma once
class COVector2;
class COTriangle
{
public:
	COVector2* vertexArray;
	COTriangle(COVector2*);
	void print();
	static bool isTriangle(COVector2*);
	bool isInTriangle(COVector2*);
};
