#include "GameBG.h"

GameBG::GameBG()
{
}

GameBG::GameBG(BG_DATA bg_data)
{
	GameBgInit(bg_data);
}


GameBG::~GameBG()
{
}

bool GameBG::GameBgInit(BG_DATA bg_data)
{
	if (Img_List.size() < static_cast<int> (GAME_BG_TYPE::BGMAX))
	{
		Img_List.insert(std::make_pair(GAME_BG_TYPE::BASE, "πﬁ∞—îwåi"));
	}
	image = Img_List[std::get<static_cast<int>(BG_STATE::IMAGE)>(bg_data)];
	_pos = std::get<static_cast<int>(BG_STATE::POS)>(bg_data);
	return false;
}

void GameBG::Update(void)
{
	_pos.x--;
}
