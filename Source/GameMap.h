namespace game_framework {

	//
	// 未完成
	// 
	// 
	// size
	// madeline 48 x 48
	//
	//	block 24 x 24
	// map size is 20 x 26


	class GameMap{
	public:
		GameMap();
		void LoadBitmap();				// 載入地圖
		void OnShow();					// 顯示地圖
		void OnMove();
		~GameMap();					//解構子
	protected:
		const int MAP_SIZE_H;
		const int MAP_SIZE_W;

		CMovingBitmap block_1;		
		int map[20][26];				// 建立一個地圖矩陣的index
		const int X, Y;					// 大地圖的左上角x, y座標
		const int MW, MH;				// 每張小地圖的寬高度
	};
}