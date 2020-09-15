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
	Img_List.insert(std::make_pair(R_UI_TYPE::BG, "���ٔw�i"));
	Img_List.insert(std::make_pair(R_UI_TYPE::RANKING, "�ݷݸ�"));
	Img_List.insert(std::make_pair(R_UI_TYPE::RESTART, "ؽ���"));
	Img_List.insert(std::make_pair(R_UI_TYPE::TITLE, "����"));
	Img_List.insert(std::make_pair(R_UI_TYPE::EXIT, "�o��"));
	Img_List.insert(std::make_pair(R_UI_TYPE::GAMECLEAR, "�ްѸر"));
	
	image = Img_List.at(std::get<static_cast<int>(BG_STATE::IMAGE)>(bg_data));
	_pos = std::get<static_cast<int>(BG_STATE::POS)>(bg_data);
	return false;
}