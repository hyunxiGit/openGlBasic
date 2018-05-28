#pragma once
#include "COVector.h"
#include <iostream>


struct COMatrix3
{
	float m11; float m21; float m31;
	float m12; float m22; float m32;
	float m13; float m23; float m33;
};

class Matrix
{
public:
	static COMatrix3 makeCOMatrix3 ( float , float , float , float , float , float , float , float , float );
	static COMatrix3 makeTransformCoMatrix ( float , float );
	static COMatrix3 makeRotateMatrix ( double );
	static COMatrix3 makeScaleMatrix ( float , float );
	static COMatrix3 concatenate ( COMatrix3 , COMatrix3);
	
	static COVector2  convertByMatrix ( COMatrix3 , COVector2 );
	static COVector2 transform ( COVector2, float , float);
	static COVector2 rotate    (  COVector2 , double);
	static COVector2 scale     (  COVector2 , float , float);

	static void print(COMatrix3);
};

const COMatrix3 COMATRIX_IDENDITY = Matrix::makeCOMatrix3(1.0f, 0.0f , 0.0f , 0.0f , 1.0f , 0.0f , 0.0f ,  0.0f , 1.0f);
