#pragma once
#include "Bg.h"
#include <map>

enum GAME_BG_TYPE
{
	BASE,
	BGMAX
};

using BG_DATA = std::tuple<GAME_BG_TYPE, Vector2Dbl, Vector2Dbl>;					// <画像ﾀｲﾌﾟ、座標、ｻｲｽﾞ>

class GameBG :
	public Bg
{
public:
	GameBG();
	GameBG(BG_DATA bg_data);
	void Scroll() override;
	bool GetJudge();
	~GameBG();
private:
	bool GameBgInit(BG_DATA bg_data);							// IMGLISTに登録する
	void Update(void);
	bool Judge(void);
	bool _judge;											// 削除するべきの時true
	std::map <GAME_BG_TYPE, std::string> Img_List;					// 画像ﾘｽﾄ
};

