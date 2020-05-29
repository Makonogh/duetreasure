#pragma once
#include "Bg.h"
#include <tuple>
#include <map>

enum class UI_TYPE
{
	BG,
	LOGO,
	GAMESTART,
	HOW_TO,
	RANKING,
	EXIT,
	ICON,
	BLACK,
	CONTROLER,
	MARO,
	MAROKO,
	MAX
};

using BG_DATA = std::tuple<UI_TYPE, Vector2Dbl, Vector2>;

class TitleBg :
	public Bg
{
public:
	TitleBg();
	TitleBg(BG_DATA);
	~TitleBg();
private:
	bool TitleBgInit(BG_DATA);
	std::map<UI_TYPE, std::string> Img_List;
};

