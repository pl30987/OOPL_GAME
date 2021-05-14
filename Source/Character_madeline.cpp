#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "GameMap.h"
#include "Character_madeline.h"

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
		x = 72;
		y = 240;
		isMovingLeft = false;
		isMovingRight = false;
		isMovingUp = false;
		isMovingDown = false;
		isJumping = false;
		isGrabbing = false;

		velocity_x = 0.f;
		velocity_y = 0.f;
		velocity_max = 10.f;
		velocity_min = 1.5f;
		acceleration = 3.f;
		drag = 0.8f;
		gravity = 3.f;
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
		// 移動邏輯參考 https://forum.gamer.com.tw/Co.php?bsn=60602&sn=2484
		// TODO: 考慮以狀態機來控制腳色動作
		// 
		// 移動加速度
		if (isMovingLeft)
			this->velocity_x -= this->acceleration;
		if (isMovingRight)
			this->velocity_x += this->acceleration;
		/*
		if (isMovingUp)
			this->velocity_y -= this->acceleration/2.0f;
		if (isMovingDown)
			this->velocity_y += this->acceleration/2.0f;
		//*/
		if (isJumping && isOnGround())
			this->velocity_y -= 30.f;
		if (isJumping && isOnWall() && velocity_y > 1.0f)
			this->velocity_y -= 20.f;

		// 限制移動速度
		if (std::abs(this->velocity_x) > this->velocity_max) {
			this->velocity_x = this->velocity_max * (this->velocity_x > 0.f ? 1.f : -1.f);
		}
		if (std::abs(this->velocity_x) > this->velocity_max) {
			this->velocity_y = this->velocity_max * 3.0f * (this->velocity_x > 0.f ? 1.f : -1.f);
		}

		// 物理
		// 移動衰減
		this->velocity_y += this->gravity;

		this->velocity_x = this->velocity_x * this->drag;


		if (std::abs(velocity_x) <= this->velocity_min) {
			this->velocity_x = 0;
		}
		if (std::abs(velocity_y) <= this->velocity_min) {
			this->velocity_y = 0;
		}

		// 最後位置設定
		if (isCollidedX((int)velocity_x) == true) {
			ResetVelocityX();
		}
		else {
			x = x + (int)velocity_x;
		}

		if (isCollidedY((int)velocity_y) == true) {
			ResetVelocityY();
		}
		else {
			y = y + (int)velocity_y;
		}

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

	void Character_madeline::SetJump(bool flag)
	{
		isJumping = flag;
	}

	void Character_madeline::SetGrab(bool flag)
	{
		isGrabbing = flag;
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

	bool Character_madeline::isCollidedX(int x_delta)
	{
		return this->gamemap->isCollided(x + x_delta, y, 48, 48);
	}

	bool Character_madeline::isCollidedY(int y_delta)
	{
		return this->gamemap->isCollided(x, y + y_delta, 48, 48);
	}

	bool Character_madeline::isOnGround()
	{
		return this->gamemap->isCollided(x, y, 48, 53);
	}

	bool Character_madeline::isOnWall()
	{
		return this->gamemap->isCollided(x - 5, y, 58, 36);
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

	void Character_madeline::SetGameMap(GameMap * gamemap)
	{
		this->gamemap = gamemap;
	}
}