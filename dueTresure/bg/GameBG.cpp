#include "GameBG.h"

GameBG::GameBG()
{
}

GameBG::GameBG(BG_DATA bg_data)
{
	GameBgInit(bg_data);
}

void GameBG::Scroll()
{
	_pos.x-= 5;
}

bool GameBG::GetJudge()
{
	return _judge;
}

Vector2Dbl GameBG::GetDifPos()
{
	return StartPos - _pos;
}


GameBG::~GameBG()
{
}

bool GameBG::GameBgInit(BG_DATA bg_data)
{
	if (Img_List.size() < static_cast<int> (GAME_BG_TYPE::BGMAX))
	{
		Img_List.insert(std::make_pair(GAME_BG_TYPE::BASE, "ÉQÅ[ÉÄîwåi"));
	}
	image = Img_List[std::get<static_cast<int>(BG_STATE::IMAGE)>(bg_data)];
	_pos = std::get<static_cast<int>(BG_STATE::POS)>(bg_data);
	_size = std::get<static_cast<int>(BG_STATE::SIZE)>(bg_data);
	_judge = false;
	StartPos = _pos;
	return false;
}

void GameBG::Update(void)
{
	_judge = Judge();
}

bool GameBG::Judge(void)
{
	if (_pos.x <= -(_size.x / 2))
	{
		return true;
	}
	return false;
}
