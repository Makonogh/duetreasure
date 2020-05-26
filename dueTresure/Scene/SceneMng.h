#pragma once

#include <common/Vector2.h>
#include "BaseScene.h"
#include <tuple>
#include <vector>
#include <map>
#include <Scene/LAYER.h>
#include <Input/InputState.h>

#define lpSceneMng SceneMng::GetInstance()


enum class DRAW_QUE
{
	IMAGE,
	X,
	Y,
	RAD,
	ZORDER,
	LAYER
};

using DrawQueT = std::tuple<int, double, double, double, int, LAYER>;

class SceneMng
{
public:

	static SceneMng &GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new SceneMng();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	};

	void Run(void);							// 1ﾌﾚｰﾑのﾙｰﾌﾟ
	bool AddDrawQue(DrawQueT dQue);			// 受け取った情報を確認してﾄﾞﾛｳﾘｽﾄに入れる

	const Vector2 ScreenSize;
	const Vector2 ScreenCenter;
	const Vector2 GameSize;
	const Vector2 UISize;

	bool OldReturn;							// 1フレーム前のエンターキーの押下フラグ
	bool Return;							// 現在のエンターキーの押下フラグ

private:
	static SceneMng* sInstance;
	void Draw();
	unique_Base _activeScene;				// ﾕﾆｰｸﾎﾟｲﾝﾀでｼｰﾝを管理

	std::map<LAYER, int> _screenID;
	std::vector<DrawQueT> _drawList;		// 描画ﾘｽﾄ

	SceneMng();
	~SceneMng();
	bool SysInit(void);						// ｼｽﾃﾑ全体の初期化

};

