#include "GameScene.h"
#include "Scene\SceneMng.h"
#include "ResultScene.h"
#include "bg/GameBg.h"
#include "common/ImgMng.h"

GameScene::GameScene()
{
	TRACE("�ްѼ�ݐ���");
	// �ްтŎg���摜�̓ǂݍ���
	lpImgMng.GetID("�ްєw�i", "image/gameback.png");

	// �����ŕK�v�ȃ��X�g�̃Z�b�g
	_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,lpSceneMng.ScreenCenter,lpSceneMng.ScreenSize}));
	_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,
									{lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x - 1,lpSceneMng.ScreenCenter.y},
									lpSceneMng.ScreenSize }));
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

	for (auto data : _bgList)
	{
		(*data).Update();
	}

	for (auto data : _bgList)
	{
		(*data).Draw();
	}

	return own;
}

