#include "TitleScene.h"
#include "GameScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"


TitleScene::TitleScene()
{
	TRACE("ю╡ды╪╟щ░╤░╛");
	lpImgMng.GetID("ю╡ды■w▄i", "image/titleback.png");
	lpImgMng.GetID("ю╡дыш╨ч", "image/title.png");
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

	lpSceneMng.AddDrawQue({ IMAGE_ID("ю╡ды■w▄i")[0], 600.0, 600.0, 0.0, INT_MAX, LAYER::BG });
	lpSceneMng.AddDrawQue({ IMAGE_ID("ю╡дыш╨ч")[0], 600.0, 600.0, 0.0, INT_MAX, LAYER::BG });

	return std::move(own);
}
