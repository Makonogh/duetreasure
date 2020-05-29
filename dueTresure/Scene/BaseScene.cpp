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
	if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	{
		if (sarada == 0)
		{
			sarada = 1;
			SceneCount = 0;
		}
		else sarada = 0;
	}
	
}