#include "ResultScene.h"
#include "TitleScene.h"
#include "SceneMng.h"



ResultScene::ResultScene()
{
	TRACE("ػ��ļ�ݐ���");
}


ResultScene::~ResultScene()
{
}

unique_Base ResultScene::Update(unique_Base own)
{
	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		return std::make_unique<TitleScene>();
	}
	return own;
}
