#pragma once
#include "Bg.h"
#include <tuple>
#include <map>
enum class R_UI_TYPE {
	RANKING,
	RESTART,
	TITLE,
	EXIT,
	MAX
};

using BG_DATA = std::tuple<R_UI_TYPE, Vector2Dbl, Vector2Dbl>;

class ResultBg :
	public Bg
{
public:
	ResultBg();
	ResultBg(BG_DATA);
	~ResultBg();
private:
	bool ResultBgInit(BG_DATA);
	std::map<R_UI_TYPE, std::string> Img_List;
};

