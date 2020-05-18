#include "TitleScene.h"
#include "GameScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"


TitleScene::TitleScene()
{
	TRACE("ﾀｲﾄﾙｼｰﾝ生成");
	lpImgMng.GetID("ﾀｲﾄﾙ背景", "image/titleback.png");
	lpImgMng.GetID("ﾀｲﾄﾙﾛｺﾞ", "image/title.png");
	lpImgMng.GetID("ｹﾞｰﾑｽﾀｰﾄ", "image/menu/play.png");
	lpImgMng.GetID("操作方法", "image/menu/how.png");
	lpImgMng.GetID("ﾗﾝｷﾝｸﾞ", "image/menu/titlerank.png");
	lpImgMng.GetID("出口", "image/menu/exit.png");
	lpImgMng.GetID("選択アイコン", "image/pickel3.png", { 72, 72 }, {2, 1});
	lpImgMng.GetID("操作方法2", "image/menu/controler.png");
	GraphFilter(IMAGE_ID("ﾀｲﾄﾙ背景")[0], DX_GRAPH_FILTER_GAUSS, 2, 1200);

	menuID = static_cast<int>(MENU::GAMESTART);

	//変数の初期化
	sarada = 0;
	SceneCount = 0;
	sizeOffset = 0;
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

	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		sarada = 1;
		SceneCount = 0;
	}

	switch (menuID)
	{
		case static_cast<int>(MENU::GAMESTART) :
			sizeOffset = 118;
			if(SceneCount > 60 && sarada == 1)return std::make_unique<GameScene>();
			break;
		case static_cast<int>(MENU::HOW_TO) :
			sizeOffset = 162;
			if (sarada == 1)
			{
				lpSceneMng.AddDrawQue({ IMAGE_ID("操作方法2")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, INT_MAX, LAYER::SYSTEM });
				
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

	lpSceneMng.AddDrawQue({ IMAGE_ID("ﾀｲﾄﾙ背景")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, INT_MAX, LAYER::BG });
	lpSceneMng.AddDrawQue({ IMAGE_ID("ﾀｲﾄﾙﾛｺﾞ")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y - 150, 0.0, INT_MAX, LAYER::UI });
	lpSceneMng.AddDrawQue({ IMAGE_ID("ｹﾞｰﾑｽﾀｰﾄ")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, INT_MAX, LAYER::UI });
	lpSceneMng.AddDrawQue({ IMAGE_ID("操作方法")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y + 100, 0.0, INT_MAX, LAYER::UI });
	lpSceneMng.AddDrawQue({ IMAGE_ID("ﾗﾝｷﾝｸﾞ")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y + 200, 0.0, INT_MAX, LAYER::UI });
	lpSceneMng.AddDrawQue({ IMAGE_ID("出口")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y + 300, 0.0, INT_MAX, LAYER::UI });
	lpSceneMng.AddDrawQue({ IMAGE_ID("選択アイコン")[sarada], lpSceneMng.ScreenCenter.x + sizeOffset, lpSceneMng.ScreenCenter.y +(menuID * 100), 0.0, INT_MAX, LAYER::UI });
	
	SceneCount++;

	return std::move(own);
}

