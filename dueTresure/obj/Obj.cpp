#include "Obj.h"


Obj::Obj()
{
}

Obj::~Obj()
{
}

void Obj::Update(sharedObj & list)
{
}

void Obj::Update()
{
}

void Obj::Draw(void)
{
	if (_animMap.find(_state) == _animMap.end())
	{
		return;
	}

	if (_animMap[_state].size() <= _animFrame || _animFrame < 0)
	{
		return;
	}

	// ±ÆÑÌÚ°Ñ‚ª‹K’è’l‚Ü‚Ås‚Á‚½‚ç±ÆÑ¶³ÝÄ‚ª•Ï‚í‚é‚æ‚¤‚É‚·‚é
	if (_animMap[_state][_animFrame].second <= _animCount)
	{
		if (_animMap[_state][_animFrame].first >= 0)
		{
			_animFrame++;
		}
	}

	if (_animMap[_state].size() <= _animFrame)
	{
		_animFrame = 0;
		_animCount = 0;
	}
	else
	{
		_animCount++;
	}
	lpSceneMng.AddDrawQue({ _animMap[_state][_animFrame].first ,_pos.x, _pos.y,0.0,0.0,LAYER::CHAR });
}

void Obj::Draw(int id)
{
	lpSceneMng.AddDrawQue({ id,_pos.x,_pos.y,0,0,LAYER::CHAR });
}

bool Obj::SetAnim(const STATE state, AnimVector & data)
{
	return (_animMap.try_emplace(state, std::move(data))).second;
}

Vector2Dbl Obj::GetPos()
{
	return _pos;
}

Vector2Dbl Obj::GetSize()
{
	return _size;
}

bool Obj::GetJudge()
{
	return false;
}
