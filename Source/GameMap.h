#ifndef GAMEMAP
#define GAMEMAP
namespace game_framework {

	//
	// ������
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
		~GameMap();					//�Ѻc�l
		void LoadBitmap();				// ���J�a��
		void OnShow();					// ��ܦa��
		void OnMove();

		// �I������
		bool isCollided(int pos_x, int pos_y, int height, int width);
	protected:
		const int MAP_SIZE_H;
		const int MAP_SIZE_W;

		//CMovingBitmap block_1;
		vector<CMovingBitmap> tiled;
		int map[20][26];				// �إߤ@�Ӧa�ϯx�}��index
		const int MAP_X, MAP_Y;			// �j�a�Ϫ����W��x, y�y��
		const int TILED_WIDTH, TILED_HEIGHT;				// �C�i�p�a�Ϫ��e����
	};
}
#endif