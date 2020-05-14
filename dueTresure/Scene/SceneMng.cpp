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
	// ---------¼½ÃÑˆ—
	SetWindowText("dueTresure");
	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);			// 1280*720ÄŞ¯ÄA65536FÓ°ÄŞ‚Éİ’è
	ChangeWindowMode(true);								// true:window false:ÌÙ½¸Ø°İ

	if (DxLib_Init() == -1)
	{
		return true;										// DX×²ÌŞ×Ø‰Šú‰»ˆ— ¸”s‚Ìê‡^‚ğ•Ô‚·
	}
	SetDrawScreen(DX_SCREEN_BACK);							// ÊŞ¯¸ÊŞ¯Ì§‚É•`‰æ

	return false;

}
