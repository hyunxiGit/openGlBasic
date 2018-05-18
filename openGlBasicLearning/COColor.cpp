#include "stdafx.h"
# include "COColor.h"
COColor::COColor(COColorByte myColor)
{
	//seperate channel to ByteChannel
	colorByte = myColor;
	initPtr();
}

COColor::COColor(COChanelByte* myChannelArray)
{
	int len;
	
	COColorByte tempA = myChannelArray[0] << 24 & 0xff000000;
	COColorByte tempR = myChannelArray[1] << 16 & 0x00ff0000;
	COColorByte tempG = myChannelArray[2] << 8  & 0x0000ff00;
	COColorByte tempB = myChannelArray[3]       & 0x000000ff;

	colorByte = tempA + tempR + tempG + tempB;
	COChanelByte myChannels[4];
	getChannel(myChannels);

	for (int i = 0; i < 4; i++)
	{

	}
}

COColor::COColor(float* myChannelArray)
{
	int len;

	COColorByte tempA = ((COColorByte)(255 * myChannelArray[0])) << 24 & 0xff000000;
	COColorByte tempR = ((COColorByte)(255 * myChannelArray[1])) << 16 & 0x00ff0000;
	COColorByte tempG = ((COColorByte)(255 * myChannelArray[2])) << 8  & 0x0000ff00;
	COColorByte tempB = ((COColorByte)(255 * myChannelArray[3]))       & 0x000000ff;

	colorByte = tempA + tempR + tempG + tempB;
	initPtr();
}


void COColor :: initPtr()
{
	//initialize pointer
	colorptr = &colorByte;
	cout << hex<<*colorptr << endl;
	bPtr = (COChanelByte*)(colorptr);

	gPtr = bPtr + 1;
	rPtr = bPtr + 2;
	aPtr = bPtr + 3;
}

void COColor ::COColorToFloat(float* myFloatColor)
{

	if (aPtr != nullptr && rPtr != nullptr && gPtr != nullptr && bPtr != nullptr)
	{
		cout.unsetf(ios::hex);
		myFloatColor[0] = (float)(*aPtr / 255.0);
		myFloatColor[1] = (float)(*rPtr / 255.0);	
		myFloatColor[2] = (float)(*gPtr / 255.0);
		myFloatColor[3] = (float)(*bPtr / 255.0);
	}
}

//这里应该写成一个COColor的constructer
COColorByte COColor::floatToByte(float * myFloatColor)
{
	COColorByte myByteColor = 0x0;
	
	//初始化这里还有点问题
	
	if (myFloatColor != nullptr)
	{
		int len;
		GET_ARRAY_LEN(myFloatColor, len);
		if (len != 4)
		{
			cout << "length must be 4 for color component" << endl;
			//todo: 这里需要看怎么处理参数不合法
			return (myByteColor);
		}

		//取出数组中的每个数据，转化byte， 构成 COColorByte
		COChanelByte a = (int)(255 * myFloatColor[0]);
		COChanelByte r = (int)(255 * myFloatColor[1]);
		COChanelByte g = (int)(255 * myFloatColor[2]);
		COChanelByte b = (int)(255 * myFloatColor[3]);

		COColorByte tempA = a << 24 & 0xff000000;
		COColorByte tempR = r << 16 & 0x00ff0000;
		COColorByte tempG = g << 8 & 0x0000ff00;
		COColorByte tempB = b & 0x000000ff;

		myByteColor = tempA + tempR + tempG + tempB;
		return (myByteColor);
	}
	return (myByteColor);
}

void COColor::getChannel(COChanelByte* myChannel)
{
	//myChannel长度必须为4
	myChannel[0] = (COChanelByte) (*aPtr);
	myChannel[1] = (COChanelByte) (*rPtr);
	myChannel[2] = (COChanelByte) (*gPtr);
	myChannel[3] = (COChanelByte) (*bPtr);

}

COColor COColor::operator+(COColor myColor)
{
	return myColor;
}

COColor COColor::operator*(float myScaler)
{
	
	return (colorByte * myScaler);
}

void COColor :: print(short mode = 0)
{
	switch (mode)
	{
	case 0:
		//output :  0xFFFFFF (ff,ff,ff,ff)
		cout.setf(ios::hex);
		cout << " 0x" << colorByte << " ";
		cout << "(" << (COColorByte)(*aPtr) << " , " << (COColorByte)(*rPtr) << " , " << (COColorByte)(*gPtr) << " , " << (COColorByte)(*bPtr) << " )";
		//todo : 重新写输出flolat， 因为float成员不存在了
		//cout << "(" << setprecision(2) <<aFloat << " , " << rFloat << " , " << gFloat << " , " << bFloat << " ) " << endl;
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
}