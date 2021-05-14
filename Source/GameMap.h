#ifndef GAMEMAP
#define GAMEMAP
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
		~GameMap();					//解構子
		void LoadBitmap();				// 載入地圖
		void OnShow();					// 顯示地圖
		void OnMove();

		// 碰撞偵測
		bool isCollided(int pos_x, int pos_y, int height, int width);
	protected:
		const int MAP_SIZE_H;
		const int MAP_SIZE_W;

		//CMovingBitmap block_1;
		vector<CMovingBitmap> tiled;
		int map[20][26];				// 建立一個地圖矩陣的index
		const int MAP_X, MAP_Y;			// 大地圖的左上角x, y座標
		const int TILED_WIDTH, TILED_HEIGHT;				// 每張小地圖的寬高度
	};
}
#endif