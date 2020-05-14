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
	lpImgMng.GetID("����ۺ�", "image/title.png");
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

	lpSceneMng.AddDrawQue({ IMAGE_ID("���ٔw�i")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, INT_MAX, LAYER::BG });
	lpSceneMng.AddDrawQue({ IMAGE_ID("����ۺ�")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y - 200, 0.0, INT_MAX, LAYER::UI });

	return std::move(own);
}
