#include "stdafx.h"
# include "COColor.h"

COColor Color :: makeCOColor(COChanelByte myA, COChanelByte myR, COChanelByte myG, COChanelByte myB)
{
	COColor resultColor;
	resultColor.a = myA;
	resultColor.r = myR;
	resultColor.g = myG;
	resultColor.b = myB;

	return (resultColor);
}

COColor Color::makeCOColor ( float myA , float myR, float myG, float myB )
{
	COColor resultColor;

	resultColor.a  = Color :: getByte ( myA );
	resultColor.r  = Color :: getByte ( myR );
	resultColor.g  = Color :: getByte ( myG );
	resultColor.b  = Color :: getByte ( myB );

	return (resultColor);
}

COColorByte Color::getIntColor(COColor myColor)
{
	COColorByte myResultColor;
	COColorByte _a = (myColor.a << 24) & 0xFF000000;
	COColorByte _r = (myColor.r << 16) & 0x00FF0000;
	COColorByte _g = (myColor.g <<  8) & 0x0000FF00;
	COColorByte _b = (myColor.b      ) & 0x000000FF;
	myResultColor = _a + _r + _g + _b;

	return (myResultColor);
}

COChanelByte Color::getByte(float myFloatChannel)
{
	COChanelByte resultByteChannel = 0;
	//检测参数是否合法
	if (myFloatChannel > 1 || myFloatChannel < 0)
	{
		cout << " float channel must between [0,1]";
	}
	else
	{
		resultByteChannel = (COChanelByte)(255 * myFloatChannel);
	}
	return(resultByteChannel);
}

float Color ::getFloat(COChanelByte myByteChannel)
{
	float resultFloatChannel = myByteChannel / 255.0f;
	return (resultFloatChannel);
}

COColor Color :: add(COColor myCol1, COColor myCol2)
{
	COColor myResultColor;
	myResultColor.a =  myCol1.a + myCol2.a ;
	myResultColor.r =  myCol1.r + myCol2.r ;
	myResultColor.g =  myCol1.g + myCol2.g ;
	myResultColor.b =  myCol1.b + myCol2.b ;
	return (myResultColor);
}

COColor Color :: multiply(COColor myCol, float myScaler)
{
	COColor myResultColor;
	myResultColor.a = (COChanelByte) (myCol.a * myScaler);
	myResultColor.r = (COChanelByte) (myCol.r * myScaler);
	myResultColor.g = (COChanelByte) (myCol.g * myScaler);
	myResultColor.b = (COChanelByte) (myCol.b * myScaler);
	return (myResultColor);
}