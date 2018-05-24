#pragma once
//todo : 改写Vector2, vector3 为数据结构
struct COVector2
{
	float x;
	float y;
};

struct COVector3
{
	float x;
	float y;
	float z;
};

class Vector
{
public:
	static COVector2 makeCOVector2(float, float);
	static COVector3 makeCOVector3(float, float, float);
	static COVector2 add(COVector2, COVector2);
	static COVector3 add(COVector3, COVector3);
	static COVector2 scale(COVector2, float);
	static COVector3 scale(COVector3, float);
	static bool equal(COVector2, COVector2);
	static bool equal(COVector3, COVector3);
	static void print(COVector2);
	static void print(COVector3);
};

class TCOVector2
{
public:
	float x;
	float y;
	TCOVector2(float, float);
	TCOVector2 operator+ (TCOVector2);
	TCOVector2 operator* (float);
	bool operator== (TCOVector2);
	void print();
};