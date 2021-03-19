#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character_madeline.h"

/*
遊戲角色物件
*/

namespace game_framework {
	
	Character_madeline::Character_madeline()
	{
		Initialize();
	}

	int Character_madeline::GetX1()
	{
		return x;
	}

	int Character_madeline::GetY1()
	{
		return y;
	}

	int Character_madeline::GetX2()
	{
		return x + SpriteStand.Width();
	}

	int Character_madeline::GetY2()
	{
		return y + SpriteStand.Height();
	}

	void Character_madeline::Initialize()
	{
		const int X_POS = 280;
		const int Y_POS = 400;
		x = X_POS;
		y = Y_POS;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void Character_madeline::LoadBitmap()
	{
		//
		//		角色靜態貼圖
		//
		SpriteStand.LoadBitmap("Bitmaps\\character_madeline_sprite\\Madeline_Stand.bmp", RGB(128, 0, 128));
		SpriteLookUp.LoadBitmap("Bitmaps\\character_madeline_sprite\\Madeline_LookUp.bmp", RGB(128, 0, 128));
		SpriteLookDown.LoadBitmap("Bitmaps\\character_madeline_sprite\\Madeline_LookDown.bmp", RGB(128, 0, 128));

		//
		//		角色往右走
		//
		SpriteRight.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunRight_1.bmp", RGB(128, 0, 128));
		SpriteRight.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunRight_2.bmp", RGB(128, 0, 128));
		SpriteRight.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunRight_3.bmp", RGB(128, 0, 128));
		SpriteRight.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunRight_4.bmp", RGB(128, 0, 128));
		SpriteRight.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunRight_5.bmp", RGB(128, 0, 128));
		SpriteRight.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunRight_6.bmp", RGB(128, 0, 128));

		//
		//		角色往左走
		//
		SpriteLeft.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunLeft_1.bmp", RGB(128, 0, 128));
		SpriteLeft.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunLeft_2.bmp", RGB(128, 0, 128));
		SpriteLeft.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunLeft_3.bmp", RGB(128, 0, 128));
		SpriteLeft.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunLeft_4.bmp", RGB(128, 0, 128));
		SpriteLeft.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunLeft_5.bmp", RGB(128, 0, 128));
		SpriteLeft.AddBitmap("Bitmaps\\character_madeline_sprite\\Madeline_RunLeft_6.bmp", RGB(128, 0, 128));
	}

	void Character_madeline::OnMove()
	{
		const int STEP_SIZE = 2;

		//
		//		往左走
		//
		if (isMovingLeft == true && isMovingRight == false)
			SpriteLeft.OnMove();
		else
			SpriteLeft.Reset();
		//
		//		往右走
		//
		if (isMovingLeft == false && isMovingRight == true)
			SpriteRight.OnMove();
		else
			SpriteRight.Reset();

		if (isMovingLeft)
			x -= STEP_SIZE;
		if (isMovingRight)
			x += STEP_SIZE;
		if (isMovingUp)
			y -= STEP_SIZE;
		if (isMovingDown)
			y += STEP_SIZE;
	}

	void Character_madeline::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void Character_madeline::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void Character_madeline::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void Character_madeline::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void Character_madeline::SetXY(int nx, int ny)
	{
		x = nx; y = ny;
	}

	void Character_madeline::OnShow()
	{
		//
		//		人物sprites切換
		//
		if (isMovingUp == true && isMovingDown == false)
		{
			SpriteLookUp.SetTopLeft(x, y);
			SpriteLookUp.ShowBitmap();
		}
		else if (isMovingLeft == true && isMovingRight == false)
		{
			SpriteLeft.SetTopLeft(x, y);
			SpriteLeft.OnShow();
		}
		else if (isMovingLeft == false && isMovingRight == true)
		{
			SpriteRight.SetTopLeft(x, y);
			SpriteRight.OnShow();
		}
		else if (isMovingUp == false && isMovingDown == true)
		{
			SpriteLookDown.SetTopLeft(x, y);
			SpriteLookDown.ShowBitmap();
		}
		else
		{
			SpriteStand.SetTopLeft(x, y);
			SpriteStand.ShowBitmap();
		}
	}
}