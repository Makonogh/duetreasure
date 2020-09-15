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
	// �ްтŎg���摜�̓ǂݍ���
	lpImgMng.GetID("�Q�[���w�i"				, "image/gameback.png");
	lpImgMng.GetID("��"						, "image/floor.png"		, { 1366,40 }, {1,1});
	lpImgMng.GetID("��"						, "image/hasira.png", { 150,150 }, { 1,1 });
	lpImgMng.GetID("���u���b�N"				, "image/yoko.png", { 150,150}, { 1,1 });
	lpImgMng.GetID("���v", "image/clock0.png");
	lpImgMng.GetID("1�v���C���[�ҋ@"		, "image/Idlemini.png"		, { 1500 / 15, 92}, { 15,1 });
	lpImgMng.GetID("2�v���C���[�ҋ@"		, "image/Idle2mini.png"		, { 1500 / 15,115}, { 15,1 });
	lpImgMng.GetID("1�v���C���[�_�b�V��"	, "image/Run.png"		, { 1500 / 15, 92 }, { 15,1 });
	lpImgMng.GetID("1�v���C���[���]�_�b�V��", "image/ReRun.png"		, { 1500 / 15, 92 }, { 15,1 });
	lpImgMng.GetID("2�v���C���[�_�b�V��"	, "image/Run2.png"		, { 2000 / 20,115 }, { 20,1 });
	lpImgMng.GetID("2�v���C���[���]�_�b�V��", "image/ReRun2.png"	, { 2000 /20,115 }, { 20,1 });

	lpImgMng.GetID("�S�[��"					, "image/goal2.png"		, { 192 / 3, 112}, { 3,1 });

	// �����ŕK�v�ȃ��X�g�̃Z�b�g
	//_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,lpSceneMng.ScreenCenter,lpSceneMng.ScreenSize}));
	//_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::BASE,
	//								{lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x - 1,lpSceneMng.ScreenCenter.y},
	//								lpSceneMng.ScreenSize }));
	//_bgList.emplace_back(new GameBG({ GAME_BG_TYPE::CLOCK,lpSceneMng.ScreenCenter,lpSceneMng.ScreenSize }));
	sCenter = lpSceneMng.ScreenCenter;
	sSize = lpSceneMng.ScreenSize;

	_playerList.emplace_back(new Player({ 150.0,lpSceneMng.ScreenCenter.y - 150.0}, { 1500 / 15, 60 }, PLAYER::player1));
	_playerList.emplace_back(new Player({ 150.0,600.0 }, { 1500 / 15,115 }, PLAYER::player2));

	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x , lpSceneMng.ScreenCenter.y + 120 }, { 1366,40 }, GIMMIC::FLOOR }));
	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x , lpSceneMng.ScreenCenter.y + 120 }, { 1366,40 }, GIMMIC::FLOOR }));
	
	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x , lpSceneMng.ScreenSize.y - 60 }, { 1366,40 }, GIMMIC::FLOOR }));
	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenCenter.x + lpSceneMng.ScreenSize.x , lpSceneMng.ScreenSize.y - 60 }, { 1366,40 }, GIMMIC::FLOOR }));

	_objList.emplace_back(new Gimmic({ { lpSceneMng.ScreenSize.x/2+580, lpSceneMng.ScreenSize.y/2+80 }, { 192/3,112 }, GIMMIC::GOAL }));

	for (double y = 0;y * 150 <= sSize.y; y+=1)
	{
		_objList.emplace_back(new Gimmic({ { -80 ,y * 150 }, { 150,150 }, GIMMIC::HASHIRA }));
		_objList.emplace_back(new Gimmic({ { sSize.x + 80 ,y  * 150}, { 150,150 }, GIMMIC::HASHIRA }));
	}
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

	//for (auto data : _objList)
	//{
	//	(*data).Update(_objList.front(),_bgList);
	//}
	for (auto data : _playerList)
	{
		(*data).Update(_playerList.front());
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

	Draw();
	/*lpSceneMng.AddDrawQue({ IMAGE_ID("���v")[0], lpSceneMng.ScreenCenter.x + 600, lpSceneMng.ScreenCenter.y - 330, 0.0, 1, LAYER::SYSTEM });*/
	



	return own;
}

bool GameScene::CheckHit(Vector2Dbl pos, Vector2Dbl size)
{
	for (auto data : _objList)
	{
		Vector2Dbl Opos = data->GetPos();
		Vector2Dbl Osize = data->GetSize();
		if (abs(pos.x - Opos.x) <= size.x / 2 + Osize.x / 2
			&&
			abs(pos.y - Opos.y) <= size.y / 2 + Osize.y / 2 )
		{
			return false;
		}
	}
	return true;
}



void GameScene::Draw()
{
	lpSceneMng.AddDrawQue({ IMAGE_ID("�Q�[���w�i")[0],sCenter.x / 2,sCenter.y ,0.0,INT_MAX, LAYER::BG });
	lpSceneMng.AddDrawQue({ IMAGE_ID("�Q�[���w�i")[0],sSize.x,sCenter.y ,0.0,INT_MAX, LAYER::BG });
	
	for (auto data : _objList)
	{
		(*data).Draw();
	}

	for (auto data : _playerList)
	{
		(*data).Draw();
	}
}

