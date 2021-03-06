#pragma once
#include "Bg.h"
#include <map>

enum class GAME_BG_TYPE
{
	BASE,
	CLOCK,
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
	Vector2Dbl GetDifPos();
	~GameBG();
private:
	bool GameBgInit(BG_DATA bg_data);							// IMGLISTに登録する
	void Update(void);
	Vector2Dbl StartPos;
	bool Judge(void);
	bool _judge;											// 削除するべきの時true
	std::map <GAME_BG_TYPE, std::string> Img_List;					// 画像ﾘｽﾄ
};

