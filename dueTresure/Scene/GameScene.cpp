#include "GameScene.h"
#include "Scene\SceneMng.h"
#include "ResultScene.h"
#include "bg/GameBg.h"
#include "common/ImgMng.h"
#include "obj/Player.h"
#include "obj/Gimmic.h"
#include <algorithm>
#include <iostream>
#include <vector>


GameScene::GameScene()
{
	TRACE("�ްѼ�ݐ���");
	// �ްтŎg���摜�̓ǂݍ���
	lpImgMng.GetID("�Q�[���w�i"				, "image/gameback.png");
	lpImgMng.GetID("��"						, "image/floor.png"		, { 1366,40 }, {1,1});
	lpImgMng.GetID("���v", "image/clock0.png");
	lpImgMng.GetID("1�v���C���[�ҋ@"		, "image/Idle.png"		, { 250,230}, { 15,1 });
	lpImgMng.GetID("2�v���C���[�ҋ@"		, "image/Idle2.png"		, { 3000 / 15,230 }, { 15,1 });
	lpImgMng.GetID("1�v���C���[�_�b�V��"	, "image/Run.png"		, { 250,230 }, { 15,1 });
	lpImgMng.GetID("1�v���C���[���]�_�b�V��", "image/ReRun.png"		, { 250,230 }, { 15,1 });
	lpImgMng.GetID("2�v���C���[�_�b�V��"	, "image/Run2.png"		, { 3750 / 20,230 }, { 20,1 });
	lpImgMng.GetID("2�v���C���[���]�_�b�V��", "image/ReRun2.png"	, { 3750/20,230 }, { 20,1 });

	// �����ŕK�v�ȃ��X�g�̃Z�b�g
	_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,lpSceneMng.ScreenCenter,lpSceneMng.ScreenSize}));
	_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,
									{lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x - 1,lpSceneMng.ScreenCenter.y},
									lpSceneMng.ScreenSize }));
	//_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::CLOCK,lpSceneMng.ScreenCenter,lpSceneMng.ScreenSize }));


	_objList.emplace_back(new Player({ 150.0,lpSceneMng.ScreenCenter.y - 150.0}, { 100,230 }, PLAYER::player2));
	_objList.emplace_back(new Player({ 150.0,600.0 }, { 100.0,230.0 }, PLAYER::player1));

	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x , lpSceneMng.ScreenCenter.y - 20 }, { 1366,40 }, GIMMIC::FLOOR }));
	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x , lpSceneMng.ScreenCenter.y - 20 }, { 1366,40 }, GIMMIC::FLOOR }));
}

GameScene::~GameScene()
{

}

unique_Base GameScene::Update(unique_Base own)
{
	/*if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	{
		return std::make_unique<ResultScene>();
	}*/

	for (auto data : _objList)
	{
		(*data).Update(_objList.front(),_bgList);
	}

	for (auto data : _bgList)
	{
		(*data).Update();
	}

	for (auto data : _objList)
	{
		auto itr = std::remove_if(_objList.begin(), _objList.end(), [](sharedObj& obj) {return obj->GetJudge(); });
		_objList.erase(itr, _objList.end());
	}

	if (_objList.size() <= 3)
	{
		_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x , lpSceneMng.ScreenCenter.y - 20 }, { 1366,40 }, GIMMIC::FLOOR }));
	}

	for (auto data : _bgList)
	{
		if ((*data).GetJudge())
		{
			_bgList.erase(_bgList.begin());
			_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,
				{_bgList.back()->_pos.x + lpSceneMng.ScreenSize.x - 1,lpSceneMng.ScreenCenter.y},
				lpSceneMng.ScreenSize }));
			break;
		}
	}

	lpSceneMng.AddDrawQue({ IMAGE_ID("���v")[0], lpSceneMng.ScreenCenter.x + 600, lpSceneMng.ScreenCenter.y - 330, 0.0, 1, LAYER::SYSTEM });

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

