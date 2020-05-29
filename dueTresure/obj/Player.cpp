#include "Player.h"



Player::Player()
{
}

Player::Player(Vector2Dbl pos, Vector2Dbl size, player pl)
{
	_pos = pos;
	_size = size;
	plType = pl;
	PlayerCount = 0;
	Init();
}


Player::~Player()
{
}

void Player::Update(sharedObj & list)
{
}

void Player::Init(void)
{
}
