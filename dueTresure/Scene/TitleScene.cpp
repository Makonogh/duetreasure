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
	lpSceneMng.AddDrawQue({ IMAGE_ID("¿≤ƒŸîwåi")[0], 0.0, 0.0, 0.0, 0, LAYER::BG });

	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		return std::make_unique<GameScene>();
	}

	return std::move(own);
}
