#include "TitleBg.h"
#include "common/ImgMng.h"
#include "bg/Bg.h"

TitleBg::TitleBg()
{
}

TitleBg::TitleBg(BG_DATA bg_data)
{
	TitleBgInit(bg_data);
}

TitleBg::~TitleBg()
{
}

bool TitleBg::TitleBgInit(BG_DATA bg_data)
{
	Img_List.insert(std::make_pair(UI_TYPE::BG, "ﾀｲﾄﾙ背景"));
	Img_List.insert(std::make_pair(UI_TYPE::LOGO, "ﾀｲﾄﾙﾛｺﾞ"));
	Img_List.insert(std::make_pair(UI_TYPE::GAMESTART, "ｹﾞｰﾑｽﾀｰﾄ"));
	Img_List.insert(std::make_pair(UI_TYPE::HOW_TO, "操作方法"));
	Img_List.insert(std::make_pair(UI_TYPE::RANKING, "ﾗﾝｷﾝｸﾞ"));
	Img_List.insert(std::make_pair(UI_TYPE::EXIT, "出口"));
	Img_List.insert(std::make_pair(UI_TYPE::ICON, "選択アイコン"));
	Img_List.insert(std::make_pair(UI_TYPE::BLACK, "ブラック"));
	Img_List.insert(std::make_pair(UI_TYPE::CONTROLER, "操作方法2"));
	Img_List.insert(std::make_pair(UI_TYPE::MARO, "マロ"));
	Img_List.insert(std::make_pair(UI_TYPE::MAROKO, "マロ子"));
	image = Img_List.at(std::get<static_cast<int>(BG_STATE::IMAGE)>(bg_data));
	_pos = std::get<static_cast<int>(BG_STATE::POS)>(bg_data);
	return false;
}

