#pragma once
#include "Obj.h"

#define PLAYER_SPEED 8;
#define INIT_VELOCITY 56.0f;		//初速度(ジャンプの高さ) 値上げると高くなる
#define FLAME_TIME 0.3f;			//落下の速度　値下げるとやんわり
#define G 10.0f;					//重力

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

