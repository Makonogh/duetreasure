#pragma once
#include "Obj.h"

enum class player
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
	Player(Vector2Dbl pos, Vector2Dbl size,player pl);
	~Player();
	void Update(sharedObj& list) override;
private:
	void Init(void);
	player plType;
};

