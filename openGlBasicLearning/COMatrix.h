#pragma once
#include "COVector.h"
#include <iostream>


struct COMatrix3
{
	float m11; float m21; float m31;
	float m12; float m22; float m32;
	float m13; float m23; float m33;
};

struct COMatrix4
{
	float m11; float m21; float m31; float m41;
	float m12; float m22; float m32; float m42;
	float m13; float m23; float m33; float m43;
	float m14; float m24; float m34; float m44;
};

class Matrix
{
public:
	static COMatrix3 makeCOMatrix3 ( float , float , float , float , float , float , float , float , float );
	static COMatrix3 makeTransformCoMatrix3 ( float , float );
	static COMatrix3 makeRotateMatrix3 ( double );
	static COMatrix3 makeScaleMatrix3 ( float , float );
	static COMatrix3 concatenate3 ( COMatrix3 , COMatrix3);
	
	static COVector2  convertByMatrix3 ( COMatrix3 , COVector2 );
	static COVector2 transform3 ( COVector2, float , float);
	static COVector2 rotate3    (  COVector2 , double);
	static COVector2 scale3     (  COVector2 , float , float);

	static void print(COMatrix3);

	static COMatrix4 makeCOMatrix4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
	static COMatrix4 makeTransformCoMatrix4(float, float, float);
	static COMatrix4 makeRotateXMatrix4(double);
	static COMatrix4 makeRotateYMatrix4(double);
	static COMatrix4 makeRotateZMatrix4(double);
	static COMatrix4 makeScaleMatrix4(float, float, float );
	static COMatrix4 concatenate4(COMatrix4, COMatrix4);

	static COVector3  convertByMatrix4(COMatrix4, COVector3);
	static COVector3 transform4(COVector3, float, float, float);
	static COVector3 rotateX4(COVector3, double);
	static COVector3 rotateY4(COVector3, double);
	static COVector3 rotateZ4(COVector3, double);
	static COVector3 scale4(COVector3, float, float, float);

	static void print(COMatrix4);
};

const COMatrix3 COMATRIX_IDENDITY = Matrix::makeCOMatrix3(1.0f, 0.0f , 0.0f , 0.0f , 1.0f , 0.0f , 0.0f ,  0.0f , 1.0f);
const COMatrix4 COMATRIX_IDENDITY = Matrix::makeCOMatrix4(1.0f, 0.0f , 0.0f , 0.0f , 0.0f , 1.0f , 0.0f , 0.0f , 0.0f , 0.0f , 1.0f, 0.0f , 0.0f , 0.0f , 0.0f, 1.0f);
