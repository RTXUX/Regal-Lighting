#pragma once

#include "cocos2d.h"


namespace Utils
{
	constexpr int BLOOD_BAR = 345;
	constexpr int IMAGE_SPRITE = 346;
	using namespace cocos2d;
	class CoordinateTransform
	{
	public:
		static constexpr int mapHeight = 160, mapWidth = 1600;
		static constexpr int pixelsPerTile = 32;
		/**
		 * \brief 将cocos坐标转化为瓦片图坐标
		 * \param p cocos坐标
		 * \return 瓦片图坐标
		 */
		static Point cocosToTileMap(Point p);

		/**
		 * \brief 将瓦片图坐标转化为其中心在cocos坐标系统中的坐标
		 * \param p 瓦片图坐标
		 * \return cocos坐标
		 */
		static Point tileMapCenterToCocos(Point p);

		/**
		 * \brief 将瓦片图坐标转化为其对应的矩形
		 * \param p 瓦片图坐标
		 * \return 矩形
		 */
		static Rect tileMaptoRect(Point p);
	};
}