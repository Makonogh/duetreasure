#include "TitleScene.h"
#include "GameScene.h"
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
	sizeOffset = 118;

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
	WKeyOld = WKeyNew;
	WKeyNew = CheckHitKey(KEY_INPUT_W);
	SKeyOld = SKeyNew;
	SKeyNew = CheckHitKey(KEY_INPUT_S);
	
	if (WKeyNew && !WKeyOld)
	{
		menuID--;
		if (menuID < static_cast<int>(MENU::GAMESTART))
		{
			menuID = static_cast<int>(MENU::EXIT);
		}
	}
	if (SKeyNew && !SKeyOld)
	{
		menuID++;
		if (menuID > static_cast<int>(MENU::EXIT))
		{
			menuID = static_cast<int>(MENU::GAMESTART);
		}
	}

	if (lpSceneMng.InputState.state(INPUT_ID::START).first == 1&& lpSceneMng.InputState.state(INPUT_ID::START).second == 0)
	{
		if (sarada == 0)
		{
			sarada = 1;
			SceneCount = 0;
		}
		else sarada = 0;
	}

	switch (menuID)
	{
		case static_cast<int>(MENU::GAMESTART) :
			sizeOffset = 118;
			if(SceneCount > 60 && sarada == 1)return std::make_unique<GameScene>();
			break;
		case static_cast<int>(MENU::HOW_TO) :
			sizeOffset = 162;
			//PlaySoundFile("sound/ahiru.mp3",DX_PLAYTYPE_BACK);
			if (sarada == 1)
			{
				lpSceneMng.AddDrawQue({ IMAGE_ID("操作方法2")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, 1, LAYER::SYSTEM });
				lpSceneMng.AddDrawQue({ IMAGE_ID("ブラック")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, 0, LAYER::SYSTEM});

			}
			break;
		case static_cast<int>(MENU::RANKING) :
			sizeOffset = 186;
			break;
		case static_cast<int>(MENU::EXIT) :
			sizeOffset = 112;
			break;
		default:
			break;
	}

	for (auto data : _bgList)
	{
		(*data).Draw();
	}
	lpSceneMng.AddDrawQue({ IMAGE_ID("選択アイコン")[sarada], lpSceneMng.ScreenCenter.x + sizeOffset, lpSceneMng.ScreenCenter.y + (menuID * 100), 0.0, 0, LAYER::UI });

	SceneCount++;

	return std::move(own);
}

