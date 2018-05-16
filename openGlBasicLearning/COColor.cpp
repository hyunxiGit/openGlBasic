#include "stdafx.h"
# include "COColor.h"
COColor::COColor(COColorByte myColor)
{
	//seperate channel to ByteChannel
	colorByte = myColor;
	colorptr = &colorByte;
	bPtr = (COChanelByte*)(colorptr);
	gPtr = bPtr + 1;
	rPtr = bPtr + 2;
	aPtr = bPtr + 3;
	//synch local floatChannel
	aFloat = *aPtr / 255.0;
	rFloat = *rPtr / 255.0;
	gFloat = *gPtr / 255.0;
	bFloat = *bPtr / 255;
}
COColor::COColor(float myA, float myR, float myG, float myB)
{
	//test if all float is leagal
	//if (myA)
	//convert channel to ByteChannel
	//addto colorByte
}

COColor COColor::operator+(COColor myColor)
{
	return myColor;
}

COColor COColor::operator*(float myScaler)
{
	return colorByte;
}

void COColor :: print(short mode = 0)
{
	switch (mode)
	{
	case 0:
		//output :  0xFFFFFF (1,1,1,1)
		cout << " 0x" << hex << colorByte << " ";
		cout << "(" << setprecision(2) <<aFloat << " , " << rFloat << " , " << gFloat << " , " << bFloat << " ) " << endl;
		break;

	case 1:
		//output :  0xFFFFFF (255,255,255,255)
		cout << " 0x" << hex << colorByte << " ";
		cout << "(" << oct << (int)(*aPtr) << " , " << (int)(*rPtr) << " , " << (int)(*gPtr) << " , " << (int)(*bPtr) << " )";
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
}