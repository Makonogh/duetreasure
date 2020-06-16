#pragma once
#include "Obj.h"

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
	void Update(sharedObj& list) override;
private:
	void Init(void);
	PLAYER plType;
};

