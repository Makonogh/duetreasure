#pragma once
#include "Obj.h"

#define PLAYER_SPEED 3;

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
private:
	void Init(void);
	PLAYER _player;
};

