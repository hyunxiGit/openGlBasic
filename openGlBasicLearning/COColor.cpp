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
	myResultColor = ( myColor.a << 24 ) & 0xFF000000 + \
					( myColor.r << 16 ) & 0x00FF0000 + \
					( myColor.g <<  8 ) & 0x0000FF00 + \
					myColor.b       & 0x000000FF;

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

float Color :: getFloatChannel(COChanelByte myByteChannel)
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
	myResultColor.a = myCol.a * myScaler;
	myResultColor.r = myCol.r * myScaler;
	myResultColor.g = myCol.g * myScaler;
	myResultColor.b = myCol.b * myScaler;
	return (myResultColor);
}

void Color:: print(short mode = 0)
{
	/*
	switch (mode)
	{
	case 0:
		//output :  0xFFFFFF (ff,ff,ff,ff)
		cout.setf(ios::hex);
		cout << " 0x" << colorByte << " ";
		cout << "(" << (int)(*aPtr) << " , " << (int)(*rPtr) << " , " << (int)(*gPtr) << " , " << (int)(*bPtr) << " )";
		//todo : ÖØÐÂÐ´Êä³öflolat£¬ ÒòÎªfloat³ÉÔ±²»´æÔÚÁË
		float myFloatChannel[4];
		COColorToFloat(myFloatChannel);
		cout.unsetf(ios::hex);
		cout << "(" << myFloatChannel[0] << "," << myFloatChannel[1] << "," << myFloatChannel[2] << "," << myFloatChannel[3] << ")" << endl;
		break;

	case 1:
		//output :  0xFFFFFF (255,255,255,255)
		//cout.setf(ios::hex);
		// cancel hex back to dec
		cout.unsetf(ios::hex);
		cout << " 0x" << hex << colorByte << " ";
		cout << "(" <<  (COColorByte)(*aPtr) << " , " << (COColorByte)(*rPtr) << " , " << (COColorByte)(*gPtr) << " , " << (COColorByte)(*bPtr) << " )";
		break;

	case 2:
		//output : 0xFFFFFF <Color Address> <Achannel Address, Rchannel Address, Gchannel Address, Bchannel Address,>
		cout << "0x" << hex << colorByte << " ";
		cout << "<" << static_cast<const void *>(colorptr) << "> ";
		cout << "<" << static_cast<const void *>(aPtr) <<" , " << static_cast<const void *>(rPtr) << " , " << static_cast<const void *>(gPtr) << " , " << static_cast<const void *>(bPtr) << ">" << endl;
		break;

	default:
		break;
	};
	*/
}