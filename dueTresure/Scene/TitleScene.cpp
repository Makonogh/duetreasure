#include "TitleScene.h"
#include "GameScene.h"
#include "DxLib.h"
#include <algorithm>
#include "Scene\SceneMng.h"
#include "common/ImgMng.h"
#include <bg/TitleBg.h>


TitleScene::TitleScene()
{
	TRACE("���ټ�ݐ���");
	lpImgMng.GetID("���ٔw�i", "image/titleback.png");
	lpImgMng.GetID("����ۺ�", "image/title.png");
	lpImgMng.GetID("�ްѽ���", "image/menu/play.png");
	lpImgMng.GetID("������@", "image/menu/how.png");
	lpImgMng.GetID("�ݷݸ�", "image/menu/titlerank.png");
	lpImgMng.GetID("�o��", "image/menu/exit.png");
	lpImgMng.GetID("�I���A�C�R��", "image/pickel3.png", { 72, 72 }, {2, 1});
	lpImgMng.GetID("�u���b�N", "image/menu/black.png");
	lpImgMng.GetID("������@2", "image/menu/ope3.png");
	lpImgMng.GetID("�}��", "image/maro.png");
	lpImgMng.GetID("�}���q", "image/maroko.png");

	_bgList.emplace_back(new TitleBg({ UI_TYPE::BG, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y)}, lpSceneMng.ScreenSize}));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::LOGO, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) - 200.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::GAMESTART, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) }, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::HOW_TO, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 100.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::RANKING, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 200.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::EXIT, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y) + 300.0}, lpSceneMng.ScreenSize }));
	
	//_bgList.emplace_back(new TitleBg({ UI_TYPE::BLACK, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y)}, lpSceneMng.ScreenSize }));
	//_bgList.emplace_back(new TitleBg({ UI_TYPE::CONTROLER, {static_cast<double>(lpSceneMng.ScreenCenter.x), static_cast<double>(lpSceneMng.ScreenCenter.y)}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::MAROKO, {static_cast<double>(lpSceneMng.ScreenCenter.x) - 450.0, static_cast<double>(lpSceneMng.ScreenCenter.y) + 150.0}, lpSceneMng.ScreenSize }));
	_bgList.emplace_back(new TitleBg({ UI_TYPE::MARO, {static_cast<double>(lpSceneMng.ScreenCenter.x) + 500.0, static_cast<double>(lpSceneMng.ScreenCenter.y) + 150.0}, lpSceneMng.ScreenSize }));



	GraphFilter(IMAGE_ID("���ٔw�i")[0], DX_GRAPH_FILTER_GAUSS, 2, 1200);

	menuID = static_cast<int>(MENU::GAMESTART);

	//�ϐ��̏�����
	sarada = 0;
	SceneCount = 0;
	sizeOffset = 0;
}


TitleScene::~TitleScene()
{

}

unique_Base TitleScene::Update(unique_Base own)
{
	WKeyOld = WKeyNew;
	WKeyNew = CheckHitKey(KEY_INPUT_W);
	SKeyOld = SKeyNew;
	SKeyNew = CheckHitKey(KEY_INPUT_S);


	if (WKeyNew && !WKeyOld)
	{
		menuID--;
		if (menuID < static_cast<int>(MENU::GAMESTART))
		{
			menuID = static_cast<int>(MENU::EXIT);
		}
	}
	if (SKeyNew && !SKeyOld)
	{
		menuID++;
		if (menuID > static_cast<int>(MENU::EXIT))
		{
			menuID = static_cast<int>(MENU::GAMESTART);
		}
	}

	if (lpSceneMng.Return && !lpSceneMng.OldReturn)
	{
		sarada = 1;
		SceneCount = 0;
	}

	switch (menuID)
	{
		case static_cast<int>(MENU::GAMESTART) :
			sizeOffset = 118;
			if(SceneCount > 60 && sarada == 1)return std::make_unique<GameScene>();
			break;
		case static_cast<int>(MENU::HOW_TO) :
			sizeOffset = 162;
			//PlaySoundFile("sound/ahiru.mp3",DX_PLAYTYPE_BACK);
			if (sarada == 1)
			{
				lpSceneMng.AddDrawQue({ IMAGE_ID("������@2")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, 1, LAYER::SYSTEM });
				lpSceneMng.AddDrawQue({ IMAGE_ID("�u���b�N")[0], lpSceneMng.ScreenCenter.x, lpSceneMng.ScreenCenter.y, 0.0, 0, LAYER::SYSTEM});
				
			}
			break;
		case static_cast<int>(MENU::RANKING) :
			sizeOffset = 186;

			break;
		case static_cast<int>(MENU::EXIT) :
			sizeOffset = 112;
			break;
		default:
			break;
	}
	
	for (auto data : _bgList)
	{
		(*data).Draw();
	}
	SceneCount++;

	return std::move(own);
}

