#include "ResultScene.h"
#include "TitleScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "GameScene.h"
#include "RankScene.h"
#include "common/ImgMng.h"
#include <bg/ResultBg.h>



ResultScene::ResultScene()
{
	//ïœêîÇÃèâä˙âª
	sarada = 0;
	SceneCount = 0;

	TRACE("ÿªﬁŸƒº∞›ê∂ê¨");
	lpImgMng.GetID("ÿΩ¿∞ƒ", "image/result/restart.png");
	lpImgMng.GetID("¿≤ƒŸ", "image/result/retitle.png");

	_bgList.emplace_back(new ResultBg({ R_UI_TYPE::RANKING, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) }, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new ResultBg({ R_UI_TYPE::RESTART, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 100.0 }, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new ResultBg({ R_UI_TYPE::TITLE, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 200.0 }, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new ResultBg({ R_UI_TYPE::EXIT, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 300.0 }, lpSceneMng.ScreenSize }));
	GraphFilter(IMAGE_ID("¿≤ƒŸîwåi")[0], DX_GRAPH_FILTER_GAUSS, 2, 1200);

	menuID = static_cast<int>(R_MENU::R_RANKING);
}


ResultScene::~ResultScene()
{

}

unique_Base ResultScene::Update(unique_Base own)
{
	//ëIë
	if (lpInput.state(INPUT_ID::UP1).first == 1 && lpInput.state(INPUT_ID::UP1).second == 0)
	{
		menuID++;
		if (menuID < R_RANKING)
		{
			menuID = R_EXIT;
		}
	}
	if (lpInput.state(INPUT_ID::DOWN1).first == 1 && lpInput.state(INPUT_ID::DOWN1).second == 0)
	{
		menuID--;
		if (menuID > R_RANKING)
		{
			menuID = R_EXIT;
		}
	}

	SelectPath();

	switch (menuID)
	{
		case static_cast<int>(R_MENU::R_RANKING) :
			if (SceneCount > 60 && sarada == 1)return std::make_unique<RankScene>();
			break;

		case static_cast<int>(R_MENU::R_RESTART) :
			if (SceneCount > 60 && sarada == 1)return std::make_unique<GameScene>();
			break;

		case static_cast<int>(R_MENU::R_TITLE) :
			if (SceneCount > 60 && sarada == 1)return std::make_unique<TitleScene>();
			break;

		case static_cast<int>(R_MENU::R_EXIT) :
			if (SceneCount > 60 && sarada == 1)lpSceneMng.ExitFlag = true;
			break;

		default:
			break;
	}

	//if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	//{
	//	return std::make_unique<TitleScene>();
	//}

	for (auto data : _bgList)
	{
		(*data).Draw();
	}

	SceneCount++;

	return std::move(own);
}
