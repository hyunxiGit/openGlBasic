#include "stdafx.h"
#include "COVector.h"

COVector2 Vector :: makeCOVector2(float myX, float myY)
{
	COVector2 resultVector;
	resultVector. x = myX;
	resultVector. y = myY;
	return (resultVector);
}
COVector3 Vector:: makeCOVector3(float myX , float myY , float myZ) 
{
	COVector3 resultVector;
	resultVector.x = myX;
	resultVector.y = myY;
	resultVector.z = myZ;
	return (resultVector);
}
COVector2 Vector::add(COVector2 myV1, COVector2 myV2)
{
	COVector2 resultVector;
	resultVector.x = myV1.x + myV2.x;
	resultVector.y = myV1.y + myV2.y;
	return (resultVector);
}
COVector3 Vector::add(COVector3 myV1, COVector3 myV2) 
{
	COVector3 resultVector;
	resultVector.x = myV1.x + myV2.x;
	resultVector.y = myV1.y + myV2.y;
	resultVector.z = myV1.z + myV2.z;
	return(resultVector);
}
COVector2 Vector::scale(COVector2 myV, float myScaler) 
{
	COVector2 resultVector;
	resultVector.x = (float)(myV.x * myScaler);
	resultVector.y = (float)(myV.y * myScaler);
	return (resultVector);
}
COVector3 Vector::scale(COVector3 myV, float myScaler) 
{
	COVector3 resultVector;
	resultVector.x = (float)(myV.x * myScaler);
	resultVector.y = (float)(myV.y * myScaler);
	resultVector.z = (float)(myV.z * myScaler);
	return (resultVector);
}

bool Vector ::equal(COVector2 myV1, COVector2 myV2)
{
	bool result = false;
	if (myV1.x == myV2.x && myV1.y == myV2.y)
	{
		result = true;
	}

	return (result);
}
bool Vector :: equal(COVector3 myV1, COVector3 myV2)
{
	bool result = false;
	if (myV1.x == myV2.x && myV1.y == myV2.y && myV1.z == myV2.z)
	{
		result = true;
	}

	return (result);
}

void Vector::print(COVector2 myV) 
{
	cout << (myV.x, myV.y)<<endl;
}

void Vector::print(COVector3 myV) 
{
	cout << (myV.x, myV.y, myV.z) << endl;
}

void coTestFunction()
{
	printf("this is coTestFunction");
}


