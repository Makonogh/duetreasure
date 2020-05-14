#include "TitleScene.h"
#include "GameScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"


TitleScene::TitleScene()
{
	TRACE("���ټ�ݐ���");
	lpImgMng.GetID("���ٔw�i", "image/titleback.png");
	
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

	lpSceneMng.AddDrawQue({ IMAGE_ID("���ٔw�i")[0], 600.0, 600.0, 0.0, INT_MAX, LAYER::BG });

	return std::move(own);
}
