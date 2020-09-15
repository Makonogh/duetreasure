#pragma once
#include "Obj.h"

#define PLAYER_SPEED 8;
#define INIT_VELOCITY 56.0f;		//�����x(�W�����v�̍���) �l�グ��ƍ����Ȃ�
#define FLAME_TIME 0.3f;			//�����̑��x�@�l������Ƃ����
#define G 10.0f;					//�d��

enum class PLAYER
{
	player1,
	player2,
	MAX
};

struct Dir
{
	bool up;
	bool down;
	bool right;
	bool left;
};

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2Dbl pos, Vector2Dbl size,PLAYER pl);
	~Player();
	void Update(GameScene& data) override;
	bool GetJudge();
	bool _jumpFlag;
	int _jumpFrame;
	Dir dir;
private:
	void Init(void);
	PLAYER _player;
};

