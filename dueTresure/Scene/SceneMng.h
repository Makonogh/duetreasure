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

	void Run(void);							// 1�ڰт�ٰ��

	const Vector2 ScreenSize;
	const Vector2 ScreenCenter;
	const Vector2 GameSize;
	const Vector2 UISize;

	bool OldReturn;							// 1�t���[���O�̃G���^�[�L�[�̉����t���O
	bool Return;							// ���݂̃G���^�[�L�[�̉����t���O

private:
	static SceneMng* sInstance;

	unique_Base _activeScene;				// �ư��߲���ż�݂��Ǘ�

	SceneMng();
	~SceneMng();
	bool SysInit(void);						// ���ёS�̂̏�����
};

