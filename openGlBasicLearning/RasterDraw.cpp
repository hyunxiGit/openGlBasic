#include "stdafx.h"
#include "RasterDraw.h"
#include "Raster.h"
#include "COTriangle.h"
#include "COVector.h"
RasterDraw :: RasterDraw(){}
void RasterDraw::drawTriangle(Raster *_tarRaster, COTriangle *tarTriangle)
{
	int rasterWidth   = _tarRaster->width;
	int rasterHeight  = _tarRaster->height;
	COColor **pPixels = _tarRaster->pPixels;
	
	COColor fillColor = 0xFF00FF;

	for (int y = 0; y < rasterHeight; y++)
	{
		for (int x = 0; x < rasterWidth; x++)
		{
			COVector2 curPixel(x, y);
			if (tarTriangle->isInTriangle(&curPixel))
			{
				//check if the coordinat is in the tri
				pPixels[y][x] = fillColor;
			}
		}
	}
}