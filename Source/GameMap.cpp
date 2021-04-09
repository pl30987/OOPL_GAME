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
	// 
	//

	GameMap::GameMap()
		:X(20), Y(40), MW(120), MH(100)					// 給予地圖上左上角座標及每張小圖寬高
	{
		int map_init[4][5] = {
			{0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 2, 1},
			{2, 2, 2, 2, 2} };
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
				map[i][j] = map_init[i][j];

		random_num = 0;					//初始化隨機個數
	}

	void GameMap::LoadBitmap()
	{
		blue.LoadBitmap(IDB_BLUE);
		green.LoadBitmap(IDB_GREEN);
	}

	void GameMap::OnShow()
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 4; j++)
			{
				switch (map[j][i]) {
				case 0:
					break;
				case 1:
					blue.SetTopLeft(X + (MW * i), Y + (MH * j));
					blue.ShowBitmap();
					break;
				case 2:
					green.SetTopLeft(X + (MW * i), Y + (MH * j));
					green.ShowBitmap();
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