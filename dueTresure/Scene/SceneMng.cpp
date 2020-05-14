#include "DxLib.h"
#include "BaseScene.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "TitleScene.h"
#include <algorithm>
#include <_debug/_DebugConOut.h>

SceneMng* SceneMng::sInstance = nullptr;

SceneMng::SceneMng() :ScreenSize{ 1366,768 }, ScreenCenter{ ScreenSize / 2 }, GameSize{ ScreenSize.x,576 }, UISize{ ScreenSize - GameSize }
{
}

void SceneMng::Draw()
{
	std::sort(_drawList.begin(), _drawList.end(), [](DrawQueT dQueA, DrawQueT dQueB)			// ﾘｽﾄをｿｰﾄする
	{
		return
			std::tie(std::get<static_cast<int>(DRAW_QUE::LAYER)>(dQueA), std::get<static_cast<int>(DRAW_QUE::ZORDER)>(dQueA))
			<
			std::tie(std::get<static_cast<int>(DRAW_QUE::LAYER)>(dQueB), std::get<static_cast<int>(DRAW_QUE::ZORDER)>(dQueB));
	});

	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	for (auto layer : LAYER())
	{
		SetDrawScreen(_screenID[layer]);
		ClsDrawScreen();
	}

	for (auto dQue : _drawList)
	{
		double x, y, rad;
		int id;
		LAYER layer;

		std::tie(id, x, y, rad, std::ignore, layer) = dQue;
		if (_screenID[layer] != GetDrawScreen())
		{
			SetDrawScreen(_screenID[layer]);
		}

		DrawRotaGraph(
			static_cast<int>(x),
			static_cast<int>(y),
			1.0,
			rad,
			id,
			true
		);
	}

	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	for (auto layer : LAYER())
	{
		DrawRotaGraph(ScreenCenter.x,
			ScreenCenter.y,
			1.0,
			0,
			_screenID[layer],
			true);

	}

	ScreenFlip();
}

bool SceneMng::AddDrawQue(DrawQueT dQue)
{
	if (std::get <static_cast<int>(DRAW_QUE::IMAGE)>(dQue) <= 0)
	{
		// 画像IDが不正なので、追加しない
		return false;
	}
	// Queを追加
	_drawList.emplace_back(dQue);

	return true;
}

SceneMng::~SceneMng()
{
}

void SceneMng::Run(void)
{
	SysInit();
	_activeScene = std::make_unique<TitleScene>();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_drawList.clear();				// 要素をｸﾘｱする
		OldReturn = Return;
		Return = CheckHitKey(KEY_INPUT_RETURN);
		_activeScene = (*_activeScene).Update(std::move(_activeScene));

		Draw();
	}
}



bool SceneMng::SysInit(void)
{
	// ---------ｼｽﾃﾑ処理
	SetWindowText("dueTresure");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);			// 1280*720ﾄﾞｯﾄ、65536色ﾓｰﾄﾞに設定
	ChangeWindowMode(true);								// true:window false:ﾌﾙｽｸﾘｰﾝ

	if (DxLib_Init() == -1)
	{
		return true;										// DXﾗｲﾌﾞﾗﾘ初期化処理 失敗の場合真を返す
	}
	SetDrawScreen(DX_SCREEN_BACK);							// ﾊﾞｯｸﾊﾞｯﾌｧに描画


	for (auto layer : LAYER())
	{
		_screenID.try_emplace(layer, MakeScreen(ScreenSize.x, ScreenSize.y, true));
	}

	return false;

}
