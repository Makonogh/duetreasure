#include "BaseScene.h"

BaseScene::BaseScene()
{
}


BaseScene::~BaseScene()
{

}

void BaseScene::SelectPath()//vectorŒ^ _menuList
{
	//Œˆ’è
	if (lpInput.state(INPUT_ID::BTN_2).first == 1 && lpInput.state(INPUT_ID::BTN_2).second == 0)
	{
		if (SelectCheck == 0)
		{
			SelectCheck = 1;
			SceneCount = 0;
		}
		else SelectCheck = 0;
	}
}