#include "Player.h"
#include "common/ImgMng.h"

Player::Player()
{
}

Player::Player(Vector2Dbl pos, Vector2Dbl size, PLAYER pl)
{
	_pos = pos;
	_size = size;
	_player = pl;
	if (PLAYER::player1 == pl)
	{
		_state = STATE::NORMAL1;
	}
	else
	{
		_state = STATE::NORMAL2;
	}
	PlayerCount = 0;
	Init();
}


Player::~Player()
{
}

void Player::Update(sharedObj & list)
{
	PlayerCount++;
	if (_player == PLAYER::player1)
	{
		if (lpInput.state(INPUT_ID::RIGHT1).first != 0)
		{
			_state = STATE::DASH1;
			_pos.x += PLAYER_SPEED;
		}
		else if (lpInput.state(INPUT_ID::LEFT1).first != 0)
		{
			_state = STATE::DASH1;
			_pos.x -= PLAYER_SPEED;
		}
		else
		{
			_state = STATE::NORMAL1;
		}
	}
	else
	{
		if (lpInput.state(INPUT_ID::RIGHT2).first != 0)
		{
			_state = STATE::DASH2;
			_pos.x += PLAYER_SPEED;
		}
		else if (lpInput.state(INPUT_ID::LEFT2).first != 0)
		{
			_state = STATE::DASH2;
			_pos.x -= PLAYER_SPEED;
		}
		else
		{
			_state = STATE::NORMAL2;
		}
	}
}

void Player::Init(void)
{
	AnimVector data;

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("1�v���C���[�ҋ@")[i], (i + 1) * 2);
	}
	SetAnim(STATE::NORMAL1, data);

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("2�v���C���[�ҋ@")[i], (i + 1) * 2);
	}
	SetAnim(STATE::NORMAL2, data);

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("1�v���C���[�_�b�V��")[i], (i + 1) * 2);
	}
	SetAnim(STATE::DASH1, data);


	data.reserve(20);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("2�v���C���[�_�b�V��")[i], (i + 1) * 2);
	}
	SetAnim(STATE::DASH2, data);
}
