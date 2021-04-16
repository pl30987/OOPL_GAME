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
		void LoadBitmap();				// ���J�a��
		void OnShow();					// ��ܦa��
		void OnMove();
		~GameMap();					//�Ѻc�l
	protected:
		const int MAP_SIZE_H;
		const int MAP_SIZE_W;

		CMovingBitmap block_1;		
		int map[20][26];				// �إߤ@�Ӧa�ϯx�}��index
		const int X, Y;					// �j�a�Ϫ����W��x, y�y��
		const int MW, MH;				// �C�i�p�a�Ϫ��e����
	};
}