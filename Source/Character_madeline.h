namespace game_framework {
	/*
	*�C������
	*/


	class Character_madeline {
	public:
		Character_madeline();
		int  GetX1();					// ���l���W�� x �y��
		int  GetY1();					// ���l���W�� y �y��
		int  GetX2();					// ���l�k�U�� x �y��
		int  GetY2();					// ���l�k�U�� y �y��
		void Initialize();				// �]�w���l����l��
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// �������l
		void OnShow();					// �N���l�ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w���l���W���y��
	private:
		//		madeline
		CMovingBitmap SpriteStand;			//�R��
		CMovingBitmap SpriteLookUp;			//�V�W��
		CMovingBitmap SpriteLookDown;		//�V�U��
		CAnimation SpriteLeft;				//����
		CAnimation SpriteRight;				//���k



		int x, y;					// ���l���W���y��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����

		bool isInAir;				// �O�_�b�Ť��A�M�w�i�H���D������

		
		bool isRising;			// true��W�ɡBfalse��U��
		int jumpVelocity;		// ���D���O��
		int velocity;			// �ثe���t��(�I/��)

		int floor;				// �a�O��Y�y�� �Ȯɩ�
	};


}