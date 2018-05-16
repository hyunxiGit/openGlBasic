#pragma once
#include "stdafx.h"

class CORaster;
class COTriangle;

class RasterDraw
{
public:
	RasterDraw();
	static void drawTriangle(CORaster*, COTriangle*);
};