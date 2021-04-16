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
		:X(10), Y(10), MW(24), MH(24)					// 給予地圖上左上角座標及每張小圖寬高
	{
		//簡易地圖
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 26; j++) {
				if (j == 25) {
					map[i][j] = 1;
				}
				else {
					map[i][j] = 0;
				}
			}
		}
	}

	void GameMap::LoadBitmap()
	{
		block_1.LoadBitmap("Bitmaps\\block_texture\\block_1.bmp");
	}

	void GameMap::OnShow()
	{
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 26; j++)
			{
				int tmp(map[i][j]);
				switch (tmp) {
				case 0:
					break;
				case 1:
					block_1.SetTopLeft(X + (MW * i), Y + (MH * j));
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

	GameMap::~GameMap()
	{

	}
}