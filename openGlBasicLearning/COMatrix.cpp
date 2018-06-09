#include "stdafx.h"
#include "COMatrix.h"


COMatrix3 Matrix::makeCOMatrix3(float myM11, float myM21, float myM31, float myM12, float myM22 , float myM32 , float myM13, float myM23, float myM33)
{
	COMatrix3 resultMatrix;
	resultMatrix.m11 = myM11;
	resultMatrix.m21 = myM21;
	resultMatrix.m31 = myM31;
	resultMatrix.m12 = myM12;
	resultMatrix.m22 = myM22;
	resultMatrix.m32 = myM32;
	resultMatrix.m13 = myM13;
	resultMatrix.m23 = myM23;
	resultMatrix.m33 = myM33;
	return (resultMatrix);
}

COMatrix3 Matrix::makeTransformCoMatrix3( float myTx , float myTy )
{
	COMatrix3 resultMatrix = makeCOMatrix3(1.0f , 0.0f , myTx , 0.0f, 1.0f, myTy, 0.0f, 0.0f, 1.0f);
	return (resultMatrix);
}

COMatrix3 Matrix::makeRotateMatrix3(double myRotation)
{
	COMatrix3 resultMatrix = makeCOMatrix3( (float) cos(myRotation) , (float)(-sin(myRotation)) , 0 ,\
											(float)sin(myRotation)  , (float)cos(myRotation)    , 0 , \
											0, 0, 1);
	return (resultMatrix);
}

COMatrix3 Matrix::makeScaleMatrix3(float mySx, float mySy)
{
	COMatrix3 resultMatrix = makeCOMatrix3(mySx, 0.0f , 0.0f , 0.0f, mySy, 0.0f, 0.0f, 0.0f, 1);
	return (resultMatrix);
}

COMatrix3 Matrix::concatenate3( COMatrix3 myMatrix1, COMatrix3 myMatrix2 )
{
	COMatrix3 resultMatrix;
	resultMatrix.m11 = myMatrix1.m11 * myMatrix2.m11 + myMatrix1.m21*myMatrix2.m12 + myMatrix1.m31 * myMatrix2.m13;
	resultMatrix.m21 = myMatrix1.m11 * myMatrix2.m21 + myMatrix1.m21*myMatrix2.m22 + myMatrix1.m31 * myMatrix2.m23;
	resultMatrix.m31 = myMatrix1.m11 * myMatrix2.m31 + myMatrix1.m21*myMatrix2.m32 + myMatrix1.m31 * myMatrix2.m33;

	resultMatrix.m12 = myMatrix1.m12 * myMatrix2.m11 + myMatrix1.m22*myMatrix2.m12 + myMatrix1.m32 * myMatrix2.m13;
	resultMatrix.m22 = myMatrix1.m12 * myMatrix2.m21 + myMatrix1.m22*myMatrix2.m22 + myMatrix1.m32 * myMatrix2.m23;
	resultMatrix.m32 = myMatrix1.m12 * myMatrix2.m31 + myMatrix1.m22*myMatrix2.m32 + myMatrix1.m32 * myMatrix2.m33;

	resultMatrix.m13 = myMatrix1.m13 * myMatrix2.m11 + myMatrix1.m23*myMatrix2.m12 + myMatrix1.m33 * myMatrix2.m13;
	resultMatrix.m23 = myMatrix1.m13 * myMatrix2.m21 + myMatrix1.m23*myMatrix2.m22 + myMatrix1.m33 * myMatrix2.m23;
	resultMatrix.m33 = myMatrix1.m13 * myMatrix2.m31 + myMatrix1.m23*myMatrix2.m32 + myMatrix1.m33 * myMatrix2.m33;
	return (resultMatrix);
}

COVector2 Matrix :: convertByMatrix3(COMatrix3 myM , COVector2 myV )
{
	COVector2 resultVector2;
	COVector3 _targetV = Vector::makeCOVector3(myV.x, myV.y, 1.0f);
	resultVector2.x = myM.m11 *  _targetV.x + myM.m21 *  _targetV.y + myM.m31 *  _targetV.z;
	resultVector2.y = myM.m12 *  _targetV.x + myM.m22 *  _targetV.y + myM.m32 *  _targetV.z;
	//float _m13 = myM.m13 *  _targetV.x + myM.m23 *  _targetV.y + myM.m33 *  _targetV.z;
	return (resultVector2);
}

COVector2 Matrix::transform3(COVector2 myV, float myTx, float myTy)
{
	COVector3 _targetV = Vector::makeCOVector3(myV.x, myV.y, 1.0f );
	COMatrix3 _transformMatrix = makeTransformCoMatrix3(myTx, myTy);
	COVector2 resultVector2 = convertByMatrix3(_transformMatrix , myV);
	return (resultVector2);
}

COVector2 Matrix::rotate3(COVector2 myV, double myRotation )
{
	COVector2 resultVector2;
	COMatrix3 _rotateMatrix = makeRotateMatrix3(myRotation);
	resultVector2 = convertByMatrix3(_rotateMatrix , myV );
	return (resultVector2);
}


COVector2 Matrix::scale3(COVector2 myV, float mySx, float mySy)
{
	COVector2 resultVector2;
	COMatrix3 _rotateMatrix = makeScaleMatrix3(mySx, mySy);
	resultVector2 = convertByMatrix3(_rotateMatrix , myV);
	return (resultVector2);
}

void Matrix :: print(COMatrix3 myMatrix)
{
	std :: cout << setprecision(2) <<"|" << myMatrix.m11 << "," << myMatrix.m21 << "," << myMatrix.m31 <<"|"<< std :: endl;
	std :: cout << "|" << myMatrix.m12 << "," << myMatrix.m22 << "," << myMatrix.m32 <<"|"<< std :: endl;
	std :: cout << "|" << myMatrix.m13 << "," << myMatrix.m23 << "," << myMatrix.m33 <<"|"<< std :: endl;
}

COMatrix4 Matrix::makeCOMatrix4(float myM11, float myM21, float myM31,float myM41, float myM12, float myM22, float myM32, float myM42, float myM13, float myM23, float myM33, float myM43 , float myM14, float myM24, float myM34, float myM44 )
{
	COMatrix4 resultMatrix;
	resultMatrix.m11 = myM11;
	resultMatrix.m21 = myM21;
	resultMatrix.m31 = myM31;
	resultMatrix.m41 = myM41;
	resultMatrix.m12 = myM12;
	resultMatrix.m22 = myM22;
	resultMatrix.m32 = myM32;
	resultMatrix.m42 = myM42;
	resultMatrix.m13 = myM13;
	resultMatrix.m23 = myM23;
	resultMatrix.m33 = myM33;
	resultMatrix.m43 = myM43;
	resultMatrix.m13 = myM14;
	resultMatrix.m23 = myM24;
	resultMatrix.m33 = myM34;
	resultMatrix.m43 = myM44;
	return (resultMatrix);

}
COMatrix4 Matrix::makeTransformCoMatrix4(float myTx, float myTy, float myTz)
{
	COMatrix4 resultMatrix = makeCOMatrix4(	1.0f, 0.0f, 0.0f, myTx, \
											0.0f, 1.0f, 0.0f, myTy, \
											0.0f, 0.0f, 1.0f, myTz, \
											0.0f, 0.0f, 0.0f, 1.0f );
	return (resultMatrix);
}
COMatrix4 Matrix::makeRotateXMatrix4(double myRotation)
{
	COMatrix4 resultMatrix = makeCOMatrix4(	1.0f, 0.0f, 0.0f, 0.0f, \
											0.0f, cos(myRotation) , -sin(myRotation), 0.0f,\
											0.0f, sin(myRotation) , cos(myRotation) , 0.0f,\
											0.0f, 0.0f, 0.0f, 1.0f );
	return (resultMatrix);
}
COMatrix4 Matrix::makeRotateYMatrix4(double myRotation)
{
	COMatrix4 resultMatrix = makeCOMatrix4(	cos(myRotation), 0.0f, sin(myRotation), 0.0f, \
											0.0f, 1.0f, 0.0f, 0.0f, \
											0.0f, -sin(myRotation), 0.0f , cos(myRotation), \
											0.0f, 0.0f, 0.0f, 1.0f);
	return (resultMatrix);
}
COMatrix4 Matrix::makeRotateZMatrix4(double myRotation)
{
	COMatrix4 resultMatrix = makeCOMatrix4(	cos(myRotation), -sin(myRotation), 0.0f, 0.0f, \
											sin(myRotation), cos(myRotation), 0.0f, 0.0f, \
											0.0f, 0.0f, 1.0f, 0.0f, \
											0.0f, 0.0f, 0.0f, 1.0f);
	return (resultMatrix);
}

COMatrix4 Matrix:: makeScaleMatrix4(float mySx, float mySy, float mySz)
{
	COMatrix4 resultMatrix = makeCOMatrix4(	mySx , 0.0f , 0.0f , 0.0f,\
											0.0f , mySy , 0.0f , 0.0f,\
											0.0f , 0.0f , mySz , 0.0f,\
											0.0f , 0.0f , 0.0f , 1.0f);
	return (resultMatrix);
}
COMatrix4 Matrix::concatenate4(COMatrix4 myMatrix1, COMatrix4 myMatrix2)
{
	COMatrix4 myResultMatrix;
	myResultMatrix.m11 = myMatrix1.m11 * myMatrix2.m11 + myMatrix1.m21 * myMatrix2.m12 + myMatrix1.m31 * myMatrix2.m13 + myMatrix1.m41 * myMatrix2.m14;
	myResultMatrix.m12 = myMatrix1.m12 * myMatrix2.m11 + myMatrix1.m22 * myMatrix2.m12 + myMatrix1.m32 * myMatrix2.m13 + myMatrix1.m42 * myMatrix2.m14;
	myResultMatrix.m13 = myMatrix1.m13 * myMatrix2.m11 + myMatrix1.m23 * myMatrix2.m12 + myMatrix1.m33 * myMatrix2.m13 + myMatrix1.m43 * myMatrix2.m14;
	myResultMatrix.m14 = myMatrix1.m14 * myMatrix2.m11 + myMatrix1.m24 * myMatrix2.m12 + myMatrix1.m34 * myMatrix2.m13 + myMatrix1.m44 * myMatrix2.m14;

	myResultMatrix.m21 = myMatrix1.m11 * myMatrix2.m21 + myMatrix1.m21 * myMatrix2.m22 + myMatrix1.m31 * myMatrix2.m23 + myMatrix1.m41 * myMatrix2.m24;
	myResultMatrix.m22 = myMatrix1.m12 * myMatrix2.m21 + myMatrix1.m22 * myMatrix2.m22 + myMatrix1.m32 * myMatrix2.m23 + myMatrix1.m42 * myMatrix2.m24;
	myResultMatrix.m23 = myMatrix1.m13 * myMatrix2.m21 + myMatrix1.m23 * myMatrix2.m22 + myMatrix1.m33 * myMatrix2.m23 + myMatrix1.m43 * myMatrix2.m24;
	myResultMatrix.m34 = myMatrix1.m14 * myMatrix2.m21 + myMatrix1.m24 * myMatrix2.m22 + myMatrix1.m34 * myMatrix2.m23 + myMatrix1.m44 * myMatrix2.m24;

	myResultMatrix.m31 = myMatrix1.m11 * myMatrix2.m31 + myMatrix1.m21 * myMatrix2.m32 + myMatrix1.m31 * myMatrix2.m33 + myMatrix1.m41 * myMatrix2.m34;
	myResultMatrix.m32 = myMatrix1.m12 * myMatrix2.m31 + myMatrix1.m22 * myMatrix2.m32 + myMatrix1.m32 * myMatrix2.m33 + myMatrix1.m42 * myMatrix2.m34;
	myResultMatrix.m33 = myMatrix1.m13 * myMatrix2.m31 + myMatrix1.m23 * myMatrix2.m32 + myMatrix1.m33 * myMatrix2.m33 + myMatrix1.m43 * myMatrix2.m34;
	myResultMatrix.m34 = myMatrix1.m14 * myMatrix2.m31 + myMatrix1.m24 * myMatrix2.m32 + myMatrix1.m34 * myMatrix2.m33 + myMatrix1.m44 * myMatrix2.m34;

	myResultMatrix.m41 = myMatrix1.m11 * myMatrix2.m41 + myMatrix1.m21 * myMatrix2.m42 + myMatrix1.m31 * myMatrix2.m43 + myMatrix1.m41 * myMatrix2.m44;
	myResultMatrix.m42 = myMatrix1.m12 * myMatrix2.m41 + myMatrix1.m22 * myMatrix2.m42 + myMatrix1.m32 * myMatrix2.m43 + myMatrix1.m42 * myMatrix2.m44;
	myResultMatrix.m43 = myMatrix1.m13 * myMatrix2.m41 + myMatrix1.m23 * myMatrix2.m42 + myMatrix1.m33 * myMatrix2.m43 + myMatrix1.m43 * myMatrix2.m44;
	myResultMatrix.m44 = myMatrix1.m14 * myMatrix2.m41 + myMatrix1.m24 * myMatrix2.m42 + myMatrix1.m34 * myMatrix2.m43 + myMatrix1.m44 * myMatrix2.m44;

	return(myResultMatrix);
}

COVector3 Matrix::convertByMatrix4(COMatrix4 myMatrix, COVector3 myVector)
{
	COVector3 resultVector;
	resultVector.x = myVector.x * myMatrix.m11 + myVector.y * myMatrix.m21 + myVector.z * myMatrix.m31 + myMatrix.m41;
	resultVector.y = myVector.x * myMatrix.m12 + myVector.y * myMatrix.m22 + myVector.z * myMatrix.m32 + myMatrix.m42;
	resultVector.z = myVector.x * myMatrix.m13 + myVector.y * myMatrix.m23 + myVector.z * myMatrix.m33 + myMatrix.m43;
	return(resultVector);
}
COVector3 Matrix::transform4(COVector3 myVector, float myTx, float myTy, float myTz)
{
	COVector3 resultVector;
	COMatrix4 _transMatrix = makeTransformCoMatrix4(myTx, myTy, myTz);
	resultVector = convertByMatrix4(_transMatrix, myVector);
	return(resultVector);
}
COVector3 Matrix::rotateX4(COVector3 myVector, double myRotation)
{
	COVector3 resultVector;
	COMatrix4 _rotateMatrix = makeRotateXMatrix4(myRotation);
	resultVector = convertByMatrix4(_rotateMatrix , myVector);
	return(resultVector);
}
COVector3 Matrix::rotateY4(COVector3 myVector, double myRotation)
{
	COVector3 resultVector;
	COMatrix4 _rotateMatrix = makeRotateYMatrix4(myRotation);
	resultVector = convertByMatrix4(_rotateMatrix, myVector);
	return(resultVector);
}
COVector3 Matrix::rotateZ4(COVector3 myVector, double myRotation)
{
	COVector3 resultVector;
	COMatrix4 _rotateMatrix = makeRotateZMatrix4(myRotation);
	resultVector = convertByMatrix4(_rotateMatrix, myVector);
	return(resultVector);
}

COVector3 Matrix::scale4(COVector3 myVector, float mySx, float mySy, float mySz)
{
	COMatrix4 myScaleMatrix = makeScaleMatrix4(mySx, mySy, mySz);
	COVector3 result = convertByMatrix4(myScaleMatrix, myVector);
	return(result);
}

void Matrix::print(COMatrix4 myMatrix)
{
	std::cout << setprecision(2) << "|" << myMatrix.m11 << "," << myMatrix.m21 << "," << myMatrix.m31 << "|" << myMatrix.m41 << "|" << std::endl;
	std::cout << "|" << myMatrix.m12 << "," << myMatrix.m22 << "," << myMatrix.m32 << "|" << myMatrix.m42 << "|" << std::endl;
	std::cout << "|" << myMatrix.m13 << "," << myMatrix.m23 << "," << myMatrix.m33 << "|" << myMatrix.m43 << "|" << std::endl;
	std::cout << "|" << myMatrix.m14 << "," << myMatrix.m24 << "," << myMatrix.m34 << "|" << myMatrix.m44 << "|" << std::endl;
}