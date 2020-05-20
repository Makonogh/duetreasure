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
	Img_List.insert(std::make_pair(UI_TYPE::BG, "���ٔw�i"));
	Img_List.insert(std::make_pair(UI_TYPE::LOGO, "����ۺ�"));
	Img_List.insert(std::make_pair(UI_TYPE::GAMESTART, "�ްѽ���"));
	Img_List.insert(std::make_pair(UI_TYPE::HOW_TO, "������@"));
	Img_List.insert(std::make_pair(UI_TYPE::RANKING, "�ݷݸ�"));
	Img_List.insert(std::make_pair(UI_TYPE::EXIT, "�o��"));
	Img_List.insert(std::make_pair(UI_TYPE::ICON, "�I���A�C�R��"));
	Img_List.insert(std::make_pair(UI_TYPE::BLACK, "�u���b�N"));
	Img_List.insert(std::make_pair(UI_TYPE::CONTROLER, "������@2"));
	Img_List.insert(std::make_pair(UI_TYPE::MARO, "�}��"));
	Img_List.insert(std::make_pair(UI_TYPE::MAROKO, "�}���q"));
	image = Img_List.at(std::get<static_cast<int>(BG_STATE::IMAGE)>(bg_data));
	_pos = std::get<static_cast<int>(BG_STATE::POS)>(bg_data);
	return false;
}

