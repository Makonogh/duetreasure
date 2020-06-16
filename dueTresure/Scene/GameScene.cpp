#include "GameScene.h"
#include "Scene\SceneMng.h"
#include "ResultScene.h"
#include "bg/GameBg.h"
#include "common/ImgMng.h"
#include "obj/Player.h"

GameScene::GameScene()
{
	TRACE("�ްѼ�ݐ���");
	// �ްтŎg���摜�̓ǂݍ���
	lpImgMng.GetID("�ްєw�i", "image/gameback.png");
	lpImgMng.GetID("1�v���C���[�ҋ@", "image/Idle.png", { 250,230}, { 15,1 });
	lpImgMng.GetID("2�v���C���[�ҋ@", "image/Idle21.png", { 208,227 }, { 15,1 });
	lpImgMng.GetID("1�v���C���[�_�b�V��", "image/Run.png", { 250,230 }, { 15,1 });
	lpImgMng.GetID("2�v���C���[�_�b�V��", "image/Run2.png", { 3750 / 20,230 }, { 20,1 });

	// �����ŕK�v�ȃ��X�g�̃Z�b�g
	_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,lpSceneMng.ScreenCenter,lpSceneMng.ScreenSize}));
	_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,
									{lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x - 1,lpSceneMng.ScreenCenter.y},
									lpSceneMng.ScreenSize }));

	_objList.emplace_back(new Player({ 150.0,600.0 }, { 100,150 }, PLAYER::player1));
	_objList.emplace_back(new Player({ 150.0,200.0 }, { 100,150 }, PLAYER::player2));
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

	for (auto data : _objList)
	{
		(*data).Update(_objList.front());
	}

	for (auto data : _bgList)
	{
		(*data).Update();
	}

	for (auto data : _objList)
	{
		(*data).Draw();
	}

	for (auto data : _bgList)
	{
		(*data).Draw();
	}

	return own;
}

