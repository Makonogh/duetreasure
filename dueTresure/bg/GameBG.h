#pragma once
#include "Bg.h"
#include <map>

enum GAME_BG_TYPE
{
	BASE,
	BGMAX
};

using BG_DATA = std::tuple<GAME_BG_TYPE, Vector2Dbl, Vector2Dbl>;					// <‰æ‘œÀ²ÌßAÀ•WA»²½Ş>

class GameBG :
	public Bg
{
public:
	GameBG();
	GameBG(BG_DATA bg_data);
	void Scroll() override;
	~GameBG();
private:
	bool GameBgInit(BG_DATA bg_data);							// IMGLIST‚É“o˜^‚·‚é
	void Update(void);
	bool Judge(void);
	bool _judge;											// íœ‚·‚é‚×‚«‚Ìtrue
	std::map <GAME_BG_TYPE, std::string> Img_List;					// ‰æ‘œØ½Ä
};

