#include "DxLib.h"
#include "BaseScene.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "TitleScene.h"
#include <algorithm>
#include <_debug/_DebugConOut.h>

SceneMng* SceneMng::sInstance = nullptr;

SceneMng::SceneMng() :ScreenSize{ 1280,720 }, ScreenCenter{ ScreenSize / 2 }, GameSize{ ScreenSize.x,576 }, UISize{ ScreenSize - GameSize }
{
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
		OldReturn = Return;
		Return = CheckHitKey(KEY_INPUT_RETURN);
		_activeScene = (*_activeScene).Update(std::move(_activeScene));
	}
}

bool SceneMng::SysInit(void)
{
	// ---------���я���
	SetWindowText("dueTresure");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);			// 1280*720�ޯāA65536�FӰ�ނɐݒ�
	ChangeWindowMode(true);								// true:window false:�ٽ�ذ�

	if (DxLib_Init() == -1)
	{
		return true;										// DXײ���؏��������� ���s�̏ꍇ�^��Ԃ�
	}
	SetDrawScreen(DX_SCREEN_BACK);							// �ޯ��ޯ̧�ɕ`��

	return false;

}
