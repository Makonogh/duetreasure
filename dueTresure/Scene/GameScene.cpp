#include "GameScene.h"
#include "Scene\SceneMng.h"
#include "ResultScene.h"


GameScene::GameScene()
{
	TRACE("�ްѼ�ݐ���");
}


GameScene::~GameScene()
{

}

unique_Base GameScene::Update(unique_Base own)
{
	if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	{
		return std::make_unique<ResultScene>();
	}
	return own;
}

