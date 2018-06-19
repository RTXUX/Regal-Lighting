#pragma once

#include "cocos2d.h"


namespace Utils
{
	using namespace cocos2d;
	class CoordinateTransform
	{
		static constexpr int mapHeight = 160, mapWidth = 1600;
		static constexpr int pixelsPerTile = 32;
		/**
		 * \brief ��cocos����ת��Ϊ��Ƭͼ����
		 * \param p cocos����
		 * \return ��Ƭͼ����
		 */
		static Point cocosToTileMap(Point p);

		/**
		 * \brief ����Ƭͼ����ת��Ϊ��������cocos����ϵͳ�е�����
		 * \param p ��Ƭͼ����
		 * \return cocos����
		 */
		static Point tileMapCenterToCocos(Point p);

		/**
		 * \brief ����Ƭͼ����ת��Ϊ���Ӧ�ľ���
		 * \param p ��Ƭͼ����
		 * \return ����
		 */
		static Rect tileMaptoRect(Point p);
	};
}