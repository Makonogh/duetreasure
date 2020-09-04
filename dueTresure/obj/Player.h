#pragma once
#include "Obj.h"

#define PLAYER_SPEED 8;
#define INIT_VELOCITY 50.0f;		//�����x(�W�����v�̍���) �l�グ��ƍ����Ȃ�
#define FLAME_TIME 0.3f;			//�����̑��x�@�l������Ƃ����
#define G 10.0f;					//�d��

enum class PLAYER
{
	player1,
	player2,
	MAX
};

class Player :
	public Obj
{
public:
	Player();
	Player(Vector2Dbl pos, Vector2Dbl size,PLAYER pl);
	~Player();
	void Update(sharedObj& objlist, std::vector<sharedBG> & bglist) override;
	bool GetJudge();
	bool _jumpFlag;
private:
	void Init(void);
	PLAYER _player;
};

