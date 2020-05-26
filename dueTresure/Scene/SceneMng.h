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

	void Run(void);							// 1�ڰт�ٰ��
	bool AddDrawQue(DrawQueT dQue);			// �󂯎���������m�F������۳ؽĂɓ����

	const Vector2 ScreenSize;
	const Vector2 ScreenCenter;
	const Vector2 GameSize;
	const Vector2 UISize;

	bool OldReturn;							// 1�t���[���O�̃G���^�[�L�[�̉����t���O
	bool Return;							// ���݂̃G���^�[�L�[�̉����t���O

private:
	static SceneMng* sInstance;
	void Draw();
	unique_Base _activeScene;				// �ư��߲���ż�݂��Ǘ�

	std::map<LAYER, int> _screenID;
	std::vector<DrawQueT> _drawList;		// �`��ؽ�

	SceneMng();
	~SceneMng();
	bool SysInit(void);						// ���ёS�̂̏�����

};

