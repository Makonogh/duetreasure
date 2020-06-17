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

void Gimmic::Update(sharedObj& list, std::vector<sharedBG>& bglist)
{
	if ((lpInput.state(INPUT_ID::RIGHT1).first != 0) && (lpInput.state(INPUT_ID::RIGHT2).first != 0))
	{
		_pos.x -= 5;
	}

	if (_pos.x <= - _size.x / 2)
	{
		_judge = true;
	}
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

	data.reserve(1);
	data.emplace_back(IMAGE_ID("°")[0], 0);
	SetAnim(STATE::NORMAL1, data);
}
