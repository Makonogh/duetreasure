#include <DxLib.h>								// DxLibﾗｲﾌﾞﾗﾘを使用する
#include "Scene\SceneMng.h"
#include <time.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SceneMng::GetInstance().Run();
	SceneMng::Destroy();
	return 0;
}
