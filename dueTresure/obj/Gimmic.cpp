#include "Gimmic.h"
#include "common/ImgMng.h"
#include <cmath>

Gimmic::Gimmic()
{
}

Gimmic::Gimmic(GIMMIC_DATA data)
{
	_type = std::get<static_cast<int>(OBJ_DATA::TYPE)>(data);
	_pos  = std::get<static_cast<int>(OBJ_DATA::POS)>(data);
	_size = std::get<static_cast<int>(OBJ_DATA::SIZE)>(data);
	_startPos = _pos;
	_judge = false;
	Init();
}

void Gimmic::Update()
{
}

void Gimmic::Update(GameScene& data)
{
}

void Gimmic::Draw()
{
}

bool Gimmic::GetJudge()
{
	return _judge;
}

Gimmic::~Gimmic()
{
}

void Gimmic::Init()
{
	AnimVector data;
	switch (_type)
	{
	case GIMMIC::FLOOR:
		data.reserve(1);
		data.emplace_back(IMAGE_ID("床")[0], 0);
		SetAnim(STATE::NORMAL1, data);
		break;
	case GIMMIC::HASHIRA:
		data.reserve(1);
		data.emplace_back(IMAGE_ID("柱")[0], 0);
		SetAnim(STATE::NORMAL1, data);
		break;
	case GIMMIC::BLOCK:
		data.reserve(1);
		data.emplace_back(IMAGE_ID("床ブロック")[0], 0);
		SetAnim(STATE::NORMAL1, data);
		break;
	case GIMMIC::GOAL:
		data.reserve(1);
		for (int i = 0; i < 3; i++)
		{
			data.emplace_back(IMAGE_ID("ゴール")[i], (i + 1) * 1);
		}
		SetAnim(STATE::NORMAL1, data);
		break;
	default:
		break;
	}
}
