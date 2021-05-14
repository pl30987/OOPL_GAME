#ifndef CHARACTER_MADELINE
#define CHARACTER_MADELINE
namespace game_framework {

	class GameMap;

	class Character_madeline {
	public:
		Character_madeline();
		int  GetX1();					// 擦子左上角 x 座標
		int  GetY1();					// 擦子左上角 y 座標
		int  GetX2();					// 擦子右下角 x 座標
		int  GetY2();					// 擦子右下角 y 座標
		void Initialize();				// 設定擦子為初始值
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動擦子
		void OnShow();					// 將擦子圖形貼到畫面

		void SetGameMap(GameMap * gamemap);

		//control
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetJump(bool flag);		// 
		void SetGrab(bool flag);		// 

		void SetXY(int nx, int ny);		// 設定擦子左上角座標

		//physics
		void ResetVelocityX();
		void ResetVelocityY();
		bool isCollidedX(int x_delta);
		bool isCollidedY(int y_delta);
		bool isOnGround();				// 在腳色腳底下用一個48x5的BOX來偵測
		bool isOnWall();				// 偵測是否在攀牆 腳色左右各延伸出5x36的BOX來偵測
		

	private:
		//		madeline
		CMovingBitmap SpriteStand;			//靜止
		CMovingBitmap SpriteLookUp;			//向上看
		CMovingBitmap SpriteLookDown;		//向下看
		CAnimation SpriteLeft;				//往左
		CAnimation SpriteRight;				//往右



		int x, y;					// 擦子左上角座標
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		bool isJumping;				// 是否要進行跳躍
		bool isGrabbing;			// 是否正在抓取


		// physics
		float velocity_x;			// 目前的速度(點/次)
		float velocity_y;
		float velocity_max;
		float velocity_min;
		float acceleration;
		float drag;
		float gravity;

		GameMap * gamemap;


		int floor;				// 地板的Y座標 暫時性
	};


}
#endif