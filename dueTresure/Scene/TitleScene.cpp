#include "TitleScene.h"
#include "GameScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"


TitleScene::TitleScene()
{
	TRACE("���ټ�ݐ���");
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
	return std::move(own);
}
