#include "TitleScene.h"
#include "GameScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"


TitleScene::TitleScene()
{
	TRACE("¿≤ƒŸº∞›ê∂ê¨");
	lpImgMng.GetID("¿≤ƒŸîwåi", "image/titleback.png");
	lpImgMng.GetID("¿≤ƒŸ€∫ﬁ", "image/title.png");
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

	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		switch (menuID)
		{
			case static_cast<int>(MENU::GAMESTART) :
					return std::make_unique<GameScene>();
					break;
			case static_cast<int>(MENU::HOW_TO) :
					break;
			case static_cast<int>(MENU::RANKING) :
					break;
			case static_cast<int>(MENU::EXIT):
					break;
			default:
					break;
		}
	}

	
	/*if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		menuID++;
		
			return std::make_unique<GameScene>();
		
		
	}*/


	lpSceneMng.AddDrawQue({ IMAGE_ID("¿≤ƒŸîwåi")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, INT_MAX, LAYER::BG });
	lpSceneMng.AddDrawQue({ IMAGE_ID("¿≤ƒŸ€∫ﬁ")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y - 200, 0.0, INT_MAX, LAYER::UI });

	return std::move(own);
}

