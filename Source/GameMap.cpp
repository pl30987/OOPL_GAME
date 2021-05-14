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
		:MAP_X(0), MAP_Y(0),
		TILED_WIDTH(24), TILED_HEIGHT(24),
		MAP_SIZE_H(20), MAP_SIZE_W(25)
	{


		/*²���a��
		for (int y = 0; y < 19; y++) {
			for (int x = 0; x < 26; x++) {
				map[y][x] = 0;

			}
		}
		for (int x = 0; x < 26; x++) {
			map[19][x] = 1;
		}
		//*/

		/*�T��
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 26; x++) {
				map[y][x] = 1 ? x + y >= 19 && (y > 11 || y < 9) : 0;
			}
		}
		//*/

		const int init_map[20][25] = {
		{-1, 16, 5, 21, 16, 16, 16, 21, 21, 21, 21, 14, -1, -1, 31, 31, 36, 36, 36, 36, 5, 36, 36, 51, 51},
		{ 13, 21, 6, -1, 20, 21, 22, -1, -1, -1, -1, 15, 16, 28, 36, 37, -1, -1, -1, -1, 6, -1, -1, -1, -1 },
		{ 32, -1, 6, -1, -1, -1, 6, -1, -1, -1, -1, 30, 31, 32, -1, -1, -1, -1, -1, -1, 6, -1, -1, -1, -1 },
		{ 32, -1, 6, 1, 7, -1, 6, -1, -1, -1, -1, 30, 31, 32, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1 },
		{ 32, -1, 6, -1, -1, -1, 6, -1, -1, -1, -1, 35, 36, 37, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 32, -1, 6, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 32, -1, 5, 1, 1, 1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 5, 1, 1, 7, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, -1, 6, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, -1, 6, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, 1, 1, 6, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, 15, 17, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, 11, 19, 17, 8, 8, 8, 8 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, 26, 27, -1, -1, -1, -1, -1, 15, 16, -1, 18, 11, 11, 11, 12 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, 30, 31, 32, -1, -1, -1, -1, -1, 15, 16, -1, -1, 16, 16, 16, 17 },
		{ 11, 11, 26, 27, -1, -1, -1, -1, -1, 30, 31, 32, 8, 8, 8, 8, 8, 15, 16, -1, -1, -1, -1, 31, 17 },
		{ -1, -1, 31, 32, 8, 8, 8, 8, 8, 30, 31, 33, 26, 26, 11, 11, 11, 19, -1, -1, -1, -1, -1, 31, 32 },
		{ -1, -1, 31, 33, 26, 26, 26, 26, 26, 34, 31, 31, 31, 31, 31, 16, 16, -1, -1, -1, -1, -1, -1, -1, 33 },
		{ -1, -1, 31, 31, 31, 31, 31, 31, 31, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }
		};

		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 26; x++) {
				map[y][x] = init_map[y][x];
			}
		}

	}

	void GameMap::LoadBitmap()
	{
		// ��l��tiled
		tiled.resize(55);
		int i = 0;
		stringstream path;
		vector<CMovingBitmap>::iterator iter;
		for (iter = tiled.begin(); iter < tiled.end(); iter++) {
			path << "Bitmaps\\tile\\" << (i % 1000) / 100 << (i % 100) / 10 << i % 10 << ".bmp";
			tiled[i].LoadBitmap((char *)(path.str().c_str()), RGB(255, 0, 255));
			// reset stringstream
			path.str("");
			path.clear();
			i++;
		}		
	}

	void GameMap::OnShow()
	{
		int tile_id;
		for (int y = 0; y < MAP_SIZE_H; y++)
			for (int x = 0; x < MAP_SIZE_W; x++)
			{
				tile_id = map[y][x];
				if (tile_id == -1)
					continue;
				if (tile_id < -1 || tile_id >= 55)
					ASSERT(0);
				tiled.at(tile_id).SetTopLeft(MAP_X + (TILED_WIDTH * x), MAP_Y + (TILED_HEIGHT * y));
				tiled.at(tile_id).ShowBitmap();

			}
	}

	void GameMap::OnMove()
	{

	}

	bool GameMap::isCollided(int pos_x, int pos_y, int width, int height)
	{
		for (int y = 0; y < MAP_SIZE_H; y++)
			for (int x = 0; x < MAP_SIZE_W; x++)
			{
				// ���o�����ڦ�m
				const int block_pos_x = x * 24 + MAP_X;
				const int block_pos_y = y * 24 + MAP_Y;

				// AABB
				if (map[y][x] != -1 &&
					pos_x + width - 1 > block_pos_x &&
					pos_x < block_pos_x + 23 &&
					pos_y + height - 1 > block_pos_y &&
					pos_y < block_pos_y + 23
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