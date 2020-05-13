#pragma once

#include <common/Vector2.h>
#include "BaseScene.h"
#include <tuple>
#include <vector>
#include <map>

#define lpSceneMng SceneMng::GetInstance()

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

	const Vector2 ScreenSize;
	const Vector2 ScreenCenter;
	const Vector2 GameSize;
	const Vector2 UISize;

	bool OldReturn;							// 1フレーム前のエンターキーの押下フラグ
	bool Return;							// 現在のエンターキーの押下フラグ

private:
	static SceneMng* sInstance;

	unique_Base _activeScene;				// ﾕﾆｰｸﾎﾟｲﾝﾀでｼｰﾝを管理

	SceneMng();
	~SceneMng();
	bool SysInit(void);						// ｼｽﾃﾑ全体の初期化
};

