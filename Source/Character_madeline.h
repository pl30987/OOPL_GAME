#ifndef CHARACTER_MADELINE
#define CHARACTER_MADELINE
namespace game_framework {

	class GameMap;

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

		void SetGameMap(GameMap * gamemap);

		//control
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetJump(bool flag);		// 
		void SetGrab(bool flag);		// 

		void SetXY(int nx, int ny);		// �]�w���l���W���y��

		//physics
		void ResetVelocityX();
		void ResetVelocityY();
		bool isCollidedX(int x_delta);
		bool isCollidedY(int y_delta);
		bool isOnGround();				// �b�}��}���U�Τ@��48x5��BOX�Ӱ���
		bool isOnWall();				// �����O�_�b�k�� �}�⥪�k�U�����X5x36��BOX�Ӱ���
		

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
		bool isJumping;				// �O�_�n�i����D
		bool isGrabbing;			// �O�_���b���


		// physics
		float velocity_x;			// �ثe���t��(�I/��)
		float velocity_y;
		float velocity_max;
		float velocity_min;
		float acceleration;
		float drag;
		float gravity;

		GameMap * gamemap;


		int floor;				// �a�O��Y�y�� �Ȯɩ�
	};


}
#endif