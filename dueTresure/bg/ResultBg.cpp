#include "ResultBg.h"
#include "common/ImgMng.h"
#include "bg/Bg.h"



ResultBg::ResultBg()
{

}

ResultBg::ResultBg(BG_DATA bg_data)
{
	ResultBgInit(bg_data);
}

ResultBg::~ResultBg()
{
}

bool ResultBg::ResultBgInit(BG_DATA bg_data)
{
	Img_List.insert(std::make_pair(R_UI_TYPE::BG, "À²ÄÙ”wŒi"));
	Img_List.insert(std::make_pair(R_UI_TYPE::RANKING, "×İ·İ¸Ş"));
	Img_List.insert(std::make_pair(R_UI_TYPE::RESTART, "Ø½À°Ä"));
	Img_List.insert(std::make_pair(R_UI_TYPE::TITLE, "À²ÄÙ"));
	Img_List.insert(std::make_pair(R_UI_TYPE::EXIT, "oŒû"));
	Img_List.insert(std::make_pair(R_UI_TYPE::GAMECLEAR, "¹Ş°Ñ¸Ø±"));
	
	image = Img_List.at(std::get<static_cast<int>(BG_STATE::IMAGE)>(bg_data));
	_pos = std::get<static_cast<int>(BG_STATE::POS)>(bg_data);
	return false;
}