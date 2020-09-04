#pragma once
#include "Obj.h"

#define PLAYER_SPEED 8;
#define INIT_VELOCITY 50.0f;		//初速度(ジャンプの高さ) 値上げると高くなる
#define FLAME_TIME 0.3f;			//落下の速度　値下げるとやんわり
#define G 10.0f;					//重力

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

