#pragma once

class COVector2
{
public:
	float x;
	float y;
	COVector2(float, float);
	COVector2 operator+ (COVector2);
	COVector2 operator* (float);
	bool operator== (COVector2);
	void print();
};