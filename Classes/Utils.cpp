#include "Utils.h"

namespace Utils
{
	constexpr int CoordinateTransform::mapHeight, CoordinateTransform::mapWidth, CoordinateTransform::pixelsPerTile;
	Point CoordinateTransform::cocosToTileMap(Point p)
	{
		int x, y;
		x = p.x / pixelsPerTile;
		y = (mapHeight - p.y) / pixelsPerTile;
		return Point(x,y);
	}
	Point CoordinateTransform::tileMapCenterToCocos(Point p)
	{
		int x, y;
		x = pixelsPerTile/2 + p.x * pixelsPerTile;
		y = (mapHeight / pixelsPerTile - p.y) * pixelsPerTile - pixelsPerTile/2;
		return Point(x,y);
	}

	Rect CoordinateTransform::tileMaptoRect(Point p)
	{
		int x1, y1, x2, y2;
		x1 = p.x * pixelsPerTile;
		x2 = x1 + pixelsPerTile;
		y1 = (mapHeight / pixelsPerTile - p.y-1)*pixelsPerTile;
		y2 = y1 + pixelsPerTile;
		return Rect(x1, y1, pixelsPerTile, pixelsPerTile);

	}
}
