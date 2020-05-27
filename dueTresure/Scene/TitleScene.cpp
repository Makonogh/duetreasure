#include "TitleScene.h"
#include "GameScene.h"
#include "RankScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"
#include <bg/TitleBg.h>


TitleScene::TitleScene()
{
	//変数の初期化
	sarada = 0;
	SceneCount = 0;
	IntervalOffset = 118;

	TRACE("ﾀｲﾄﾙｼｰﾝ生成");
	lpImgMng.GetID("ﾀｲﾄﾙ背景", "image/titleback.png");
	lpImgMng.GetID("ﾀｲﾄﾙﾛｺﾞ", "image/title.png");
	lpImgMng.GetID("ｹﾞｰﾑｽﾀｰﾄ", "image/menu/play.png");
	lpImgMng.GetID("操作方法", "image/menu/how.png");
	lpImgMng.GetID("ﾗﾝｷﾝｸﾞ", "image/menu/titlerank.png");
	lpImgMng.GetID("出口", "image/menu/exit.png");
	lpImgMng.GetID("選択アイコン", "image/pickel3.png", { 72, 72 }, {2, 1});
	lpImgMng.GetID("ブラック", "image/menu/black.png");
	lpImgMng.GetID("操作方法2", "image/menu/ope3.png");
	lpImgMng.GetID("マロ", "image/maro.png");
	lpImgMng.GetID("マロ子", "image/maroko.png");

	_bgList.emplace_back(new TitleBg({ UI_TYPE::BG, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y)}, lpSceneMng.ScreenSize}));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::LOGO, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) - 200.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::GAMESTART, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) }, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::HOW_TO, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 100.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::RANKING, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 200.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::EXIT, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 300.0}, lpSceneMng.ScreenSize }));
	//_bgList.emplace_back(new TitleBg({ UI_TYPE::ICON, {static_cast<double>(lpSceneMng.ScreenCenter.x) + sizeOffset, static_cast<double>(lpSceneMng.ScreenCenter.y) + (menuID * 100)}, lpSceneMng.ScreenSize }));
	//_bgList.emplace_back(new TitleBg({ UI_TYPE::BLACK, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y)}, lpSceneMng.ScreenSize }));
	//_bgList.emplace_back(new TitleBg({ UI_TYPE::CONTROLER, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y)}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::MAROKO, {static_cast<double>(lpSceneMng.ScreenCenter.x) - 450.0, static_cast<double>(lpSceneMng.ScreenCenter.y) + 150.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::MARO, {static_cast<double>(lpSceneMng.ScreenCenter.x) + 500.0, static_cast<double>(lpSceneMng.ScreenCenter.y) + 150.0}, lpSceneMng.ScreenSize }));



	GraphFilter(IMAGE_ID("ﾀｲﾄﾙ背景")[0], DX_GRAPH_FILTER_GAUSS, 2, 1200);

	menuID = static_cast<int>(MENU::GAMESTART);

	
}


TitleScene::~TitleScene()
{

}

unique_Base TitleScene::Update(unique_Base own)
{
	if (lpInput.state(INPUT_ID::UP1).first == 1 && lpInput.state(INPUT_ID::UP1).second == 0)
	{
		menuID--;
		if (menuID < static_cast<int>(MENU::GAMESTART))
		{
			menuID = static_cast<int>(MENU::EXIT);
		}
	}
	if (lpInput.state(INPUT_ID::DOWN1).first == 1 && lpInput.state(INPUT_ID::DOWN1).second == 0)
	{
		menuID++;
		if (menuID > static_cast<int>(MENU::EXIT))
		{
			menuID = static_cast<int>(MENU::GAMESTART);
		}
	}
	TRACE("%d", lpInput.state(INPUT_ID::SELECT).first);
	TRACE("%d", lpInput.state(INPUT_ID::SELECT).second);
	if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	{
		SelectPath();
	}

	switch (menuID)
	{
		case static_cast<int>(MENU::GAMESTART) :
			IntervalOffset = 118;
			if(SceneCount > 60 && sarada == 1)return std::make_unique<GameScene>();
			break;
		case static_cast<int>(MENU::HOW_TO) :
			IntervalOffset = 162;
			//PlaySoundFile("sound/ahiru.mp3",DX_PLAYTYPE_BACK);
			if (SceneCount > 60 && sarada == 1)
			{
				lpSceneMng.AddDrawQue({ IMAGE_ID("操作方法2")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, 1, LAYER::SYSTEM });
				lpSceneMng.AddDrawQue({ IMAGE_ID("ブラック")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, 0, LAYER::SYSTEM});
			}
			break;
		case static_cast<int>(MENU::RANKING) :
			IntervalOffset = 186;
			if (SceneCount > 60 && sarada == 1)return std::make_unique<RankScene>();
			break;
		case static_cast<int>(MENU::EXIT) :
			IntervalOffset = 112;
			if (SceneCount > 60 && sarada == 1)lpSceneMng.ExitFlag = true;
			break;
		default:
			break;
	}

	for (auto data : _bgList)
	{
		(*data).Draw();
	}
	lpSceneMng.AddDrawQue({ IMAGE_ID("選択アイコン")[sarada], lpSceneMng.ScreenCenter.x + IntervalOffset, lpSceneMng.ScreenCenter.y + (menuID * 100), 0.0, 0, LAYER::UI });

	SceneCount++;

	return std::move(own);
}


