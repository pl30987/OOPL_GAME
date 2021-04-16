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
	// size
	// madeline 48 x 48
	//
	//	block 24 x 24

	GameMap::GameMap()
		:X(10), Y(10), MW(24), MH(24)					// �����a�ϤW���W���y�ФΨC�i�p�ϼe��
	{
		//²���a��
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