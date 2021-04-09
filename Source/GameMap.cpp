#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "GameMap.h"

namespace game_framework {

	//
	// ������
	// 
	//

	GameMap::GameMap()
		:X(20), Y(40), MW(120), MH(100)					// �����a�ϤW���W���y�ФΨC�i�p�ϼe��
	{
		int map_init[4][5] = {
			{0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1},
			{1, 1, 1, 2, 1},
			{2, 2, 2, 2, 2} };
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 5; j++)
				map[i][j] = map_init[i][j];

		random_num = 0;					//��l���H���Ӽ�
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
					ASSERT(0);										//map�}�C���ӥX�{0, 1, 2�H�~����
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