#pragma once
#include "stdafx.h"

class Raster;
class COTriangle;

class RasterDraw
{
public:
	RasterDraw();
	static void drawTriangle(Raster*, COTriangle*);
};