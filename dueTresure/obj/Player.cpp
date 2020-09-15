#include "Player.h"
#include "common/ImgMng.h"
#include "bg/GameBg.h"
#include "Scene/GameScene.h"

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

	_velocity = { 0,0 };
	_jumpFlag = false;
	_jumpFrame = 0;

	PlayerCount = 0;
	Init();
}


Player::~Player()
{
}

void Player::Update(sharedObj & objlist)
{
	PlayerCount++;
	Vector2Dbl RotPos = _pos;
	if (_player == PLAYER::player1)
	{
		if (lpInput.state(INPUT_ID::RIGHT1).first != 0)
		{
			_state = STATE::DASH1;
			RotPos.x += PLAYER_SPEED;
			if (GameScene().CheckHit(RotPos, _size))
			{
				_pos.x += PLAYER_SPEED;
			}
		}
		else if (lpInput.state(INPUT_ID::LEFT1).first != 0)
		{
			_state = STATE::REDASH1;
			RotPos.x -= PLAYER_SPEED;
			if (GameScene().CheckHit(RotPos, _size))
			{
				_pos.x -= PLAYER_SPEED;
			}
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
			RotPos.x += PLAYER_SPEED;
			if (GameScene().CheckHit(RotPos, _size))
			{
				_pos.x += PLAYER_SPEED;
			}
		}
		else if (lpInput.state(INPUT_ID::LEFT2).first != 0)
		{
			_state = STATE::REDASH2;
			RotPos.x -= PLAYER_SPEED;
			if (GameScene().CheckHit(RotPos, _size))
			{
				_pos.x -= PLAYER_SPEED;
			}
		}
		else
		{
			_state = STATE::NORMAL2;
		}
	}

	//ジャンプ制御----------------------------------------------------------
	//ジャンプはスペース　当たり判定はポスでやってるだけ
	//PL1,PL2が連動してジャンプする
	//if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0 && _jumpFlag == false)
	//{
	//	if (_player == PLAYER::player1 && _state !=STATE::JUMP1)
	//	{
	//		_jumpFlag = true;
	//		_pos.y = 599.0f;
	//		_velocity.y = INIT_VELOCITY;
	//	}
	//	else
	//	{
	//		_jumpFlag = true;
	//		_pos.y = lpSceneMng.ScreenCenter.y - 150.0 - 1;
	//		_velocity.y = INIT_VELOCITY;
	//	}
	//}
	//float g = G;
	//float flameTime = FLAME_TIME;
	//flameTime *= g;		//(G * FLAME_TIME)
	//if (_player == PLAYER::player1)
	//{
	//	if (_pos.y < 600)
	//	{
	//		_velocity.y = _velocity.y - flameTime;
	//		_pos.y -= _velocity.y * FLAME_TIME;
	//	}
	//	else
	//	{
	//		_pos.y = 600;
	//		_jumpFlag = false;
	//	}
	//}
	//else
	//{
	//	if (_pos.y < lpSceneMng.ScreenCenter.y - 150.0)
	//	{
	//		_velocity.y = _velocity.y - flameTime;
	//		_pos.y -= _velocity.y * FLAME_TIME;
	//	}
	//	else
	//	{
	//		_pos.y = lpSceneMng.ScreenCenter.y - 150.0;
	//		_jumpFlag = false;
	//	}
	//}
	//--------------------------------------------------------------------------------------
	if (_player == PLAYER::player1)
	{
		if (lpInput.state(INPUT_ID::BTN_2).first == 1 && lpInput.state(INPUT_ID::BTN_2).second == 0 && _jumpFlag == false)
		{
			_jumpFlag = true;

		}
		if (_jumpFrame <= 15 && _jumpFlag)
		{
			RotPos.y -= 20;
			if (GameScene().CheckHit(RotPos, _size))
			{
				_pos.y -= 20;
			}
			_jumpFrame++;
		}
		else
		{
			_jumpFlag = false;
			_jumpFrame = 0;
		}
	}
	else
	{
		if (lpInput.state(INPUT_ID::BTN_4).first == 1 && lpInput.state(INPUT_ID::BTN_4).second == 0 && _jumpFlag == false)
		{

		}
	}

	RotPos.y += G;
	if (GameScene().CheckHit(RotPos, _size))
	{
		_pos.y += G;
	}
}



bool Player::GetJudge()
{
	return false;
}

void Player::Init(void)
{
	AnimVector data;

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("1プレイヤー待機")[i], (i + 1) * 1);
	}
	SetAnim(STATE::NORMAL1, data);

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("2プレイヤー待機")[i], (i + 1) * 1);
	}
	SetAnim(STATE::NORMAL2, data);

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("1プレイヤーダッシュ")[i], (i + 1) * 1);
	}
	SetAnim(STATE::DASH1, data);

	data.reserve(15);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("1プレイヤー反転ダッシュ")[i], (i + 1) * 1);
	}
	SetAnim(STATE::REDASH1, data);

	data.reserve(20);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("2プレイヤーダッシュ")[i], (i + 1) * 1);
	}
	SetAnim(STATE::DASH2, data);

	data.reserve(20);
	for (int i = 0; i < 15; i++)
	{
		data.emplace_back(IMAGE_ID("2プレイヤー反転ダッシュ")[i], (i + 1) * 1);
	}
	SetAnim(STATE::REDASH2, data);
}
