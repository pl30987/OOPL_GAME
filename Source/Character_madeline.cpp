#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Character_madeline.h"
#include "GameMap.h"

//
//遊戲角色物件
//

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
		const int FLOOR = 400;				// 地板座標
		const int X_POS = 280;
		x = X_POS;
		y = FLOOR - 1;
		isMovingLeft = false;
		isMovingRight = false;
		isMovingUp = false;
		isMovingDown = false;

		isInAir = false;
		isRising = true;

		velocity_x = 0.f;
		velocity_y = 0.f;
		velocity_max = 10.f;
		velocity_min = 1.5f;
		acceleration = 3.f;
		drag = 0.8f;
		gravity = 4.f;

		floor = FLOOR;
	}

	void Character_madeline::LoadBitmap()
	{
		SpriteRight.SetDelayCount(5);
		SpriteLeft.SetDelayCount(5);



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
		// 移動加速度
		if (isMovingLeft)
			this->velocity_x -= this->acceleration;
		if (isMovingRight)
			this->velocity_x += this->acceleration;

		// 限制移動速度
		if (std::abs(this->velocity_x) > this->velocity_max) {
			this->velocity_x = this->velocity_max * (this->velocity_x > 0.f ? 1.f : -1.f);
		}

		// 物理
		// 移動衰減
		this->velocity_y += 1.0f + this->gravity;

		this->velocity_x = this->velocity_x * this->drag;

		if (std::abs(velocity_x) <= this->velocity_min) {
			this->velocity_x = 0;
		}
		if (std::abs(velocity_y) <= this->velocity_min) {
			this->velocity_y = 0;
		}

		// 最後位置設定
		x = x + (int)velocity_x;
		y = y + (int)velocity_y;
		
		// 更新碰撞


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

	void Character_madeline::ResetVelocityX()
	{
		this->velocity_x = 0;
	}

	void Character_madeline::ResetVelocityY()
	{
		this->velocity_y = 0;
	}

	void Character_madeline::OnShow()
	{
		// 人物貼圖播放
		//		往左走
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


		//		人物sprites切換
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