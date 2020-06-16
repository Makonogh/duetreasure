#include "Player.h"
#include "common/ImgMng.h"

Player::Player()
{
}

Player::Player(Vector2Dbl pos, Vector2Dbl size, PLAYER pl)
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
	PlayerCount++;
}

void Player::Init(void)
{
	AnimVector data;

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("‘Ò‹@")[i], (i + 1) * 2);
	}
	SetAnim(STATE::NORMAL, data);

	//data.reserve(15);
	//for (int i = 0; i < 15; i++)
	//{
	//	data.emplace_back(IMAGE_ID("¼Þ¬ÝÌß")[i], (i + 1) * 2);
	//}
	//SetAnim(STATE::JUMP, data);
}
