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

COMatrix3 Matrix::makeTransformCoMatrix( float myTx , float myTy )
{
	COMatrix3 resultMatrix = makeCOMatrix3(1.0f , 0.0f , myTx , 0.0f, 1.0f, myTy, 0.0f, 0.0f, 1.0f);
	return (resultMatrix);
}

COMatrix3 Matrix::makeRotateMatrix(double myRotation)
{
	COMatrix3 resultMatrix = makeCOMatrix3( (float) cos(myRotation) , (float)(-sin(myRotation)) , 0 ,\
											(float)sin(myRotation)  , (float)cos(myRotation)    , 0 , \
											0, 0, 1);
	return (resultMatrix);
}

COMatrix3 Matrix::makeScaleMatrix(float mySx, float mySy)
{
	COMatrix3 resultMatrix = makeCOMatrix3(mySx, 0.0f , 0.0f , 0.0f, mySy, 0.0f, 0.0f, 0.0f, 1);
	return (resultMatrix);
}

COMatrix3 Matrix::concatenate( COMatrix3 myMatrix1, COMatrix3 myMatrix2 )
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

COVector2 Matrix :: convertByMatrix(COMatrix3 myM , COVector2 myV )
{
	COVector2 resultVector2;
	COVector3 _targetV = Vector::makeCOVector3(myV.x, myV.y, 1.0f);
	resultVector2.x = myM.m11 *  _targetV.x + myM.m21 *  _targetV.y + myM.m31 *  _targetV.z;
	resultVector2.y = myM.m12 *  _targetV.x + myM.m22 *  _targetV.y + myM.m32 *  _targetV.z;
	//float _m13 = myM.m13 *  _targetV.x + myM.m23 *  _targetV.y + myM.m33 *  _targetV.z;
	return (resultVector2);
}

COVector2 Matrix::transform(COVector2 myV, float myTx, float myTy)
{
	COVector3 _targetV = Vector::makeCOVector3(myV.x, myV.y, 1.0f );
	COMatrix3 _transformMatrix = makeTransformCoMatrix(myTx, myTy);
	COVector2 resultVector2 = convertByMatrix(_transformMatrix , myV);
	return (resultVector2);
}

COVector2 Matrix::rotate(COVector2 myV, double myRotation )
{
	COVector2 resultVector2;
	COMatrix3 _rotateMatrix = makeRotateMatrix(myRotation);
	resultVector2 = convertByMatrix(_rotateMatrix , myV );
	return (resultVector2);
}


COVector2 Matrix::scale(COVector2 myV, float mySx, float mySy)
{
	COVector2 resultVector2;
	COMatrix3 _rotateMatrix = makeScaleMatrix(mySx, mySy);
	resultVector2 = convertByMatrix(_rotateMatrix , myV);
	return (resultVector2);
}

void Matrix :: print(COMatrix3 myMatrix)
{
	std :: cout << setprecision(2) <<"|" << myMatrix.m11 << "," << myMatrix.m21 << "," << myMatrix.m31 <<"|"<< std :: endl;
	std :: cout << "|" << myMatrix.m12 << "," << myMatrix.m22 << "," << myMatrix.m32 <<"|"<< std :: endl;
	std :: cout << "|" << myMatrix.m13 << "," << myMatrix.m23 << "," << myMatrix.m33 <<"|"<< std :: endl;
}