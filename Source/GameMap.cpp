#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "GameMap.h"

namespace game_framework {

	//
	// 未完成
	// size
	// madeline 48 x 48
	//
	//	block 24 x 24

	GameMap::GameMap()
		:X(20), Y(0), MW(24), MH(24), MAP_SIZE_H(20), MAP_SIZE_W(25)					// 給予地圖上左上角座標及每張小圖寬高
	{

		/*簡易地圖
		for (int y = 0; y < 19; y++) {
			for (int x = 0; x < 26; x++) {
				map[y][x] = 0;

			}
		}
		for (int x = 0; x < 26; x++) {
			map[19][x] = 1;
		}
		//*/

		//*三角
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 26; x++) {
				map[y][x] = 1 ? x + y >= 19 && (y > 11 || y < 9) : 0;
			}
		}
		//*/
	}

	void GameMap::LoadBitmap()
	{
		block_1.LoadBitmap("Bitmaps\\block_texture\\block_1.bmp");
	}

	void GameMap::OnShow()
	{
		for (int y = 0; y < MAP_SIZE_H; y++)
			for (int x = 0; x < MAP_SIZE_W; x++)
			{
				int tmp(map[y][x]);
				switch (tmp) {
				case 0:
					break;
				case 1:
					block_1.SetTopLeft(X + (MW * x), Y + (MH * y));
					block_1.ShowBitmap();
					break;
				default:
					ASSERT(0);										//map陣列不該出現0, 1, 2以外的值
				}
			}
	}

	void GameMap::OnMove()
	{

	}

	bool GameMap::isCollided(int x_pos, int y_pos, int width, int height)
	{
		for (int y = 0; y < MAP_SIZE_H; y++)
			for (int x = 0; x < MAP_SIZE_W; x++)
			{
				// 取得方塊實際位置
				const int block_x_pos = x * 24 + X;
				const int block_y_pos = y * 24 + Y;

				// AABB
				if (map[y][x] != 0 &&
					x_pos + width - 1 > block_x_pos &&
					x_pos < block_x_pos + 23 &&
					y_pos + height - 1 > block_y_pos &&
					y_pos < block_y_pos + 23
					)
				{
					return true;
				}
			}
		return false;
	}

	GameMap::~GameMap()
	{

	}
}