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
	
}


TitleScene::~TitleScene()
{

}

unique_Base TitleScene::Update(unique_Base own)
{


	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		return std::make_unique<GameScene>();
	}

	lpSceneMng.AddDrawQue({ IMAGE_ID("¿≤ƒŸîwåi")[0], 600.0, 600.0, 0.0, INT_MAX, LAYER::BG });

	return std::move(own);
}
