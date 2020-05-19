#include "GameScene.h"
#include "Scene\SceneMng.h"
#include "ResultScene.h"


GameScene::GameScene()
{
	TRACE("ｹﾞｰﾑｼｰﾝ生成");
}


GameScene::~GameScene()
{

}

unique_Base GameScene::Update(unique_Base own)
{
	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		return std::make_unique<ResultScene>();
	}
	return own;
}

// キャラ