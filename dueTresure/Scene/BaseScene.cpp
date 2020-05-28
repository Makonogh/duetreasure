#include "BaseScene.h"

BaseScene::BaseScene()
{
}


BaseScene::~BaseScene()
{
}

void BaseScene::SelectPath()//vectorŒ^ _menuList
{
	//‘I‘ð
	if (lpInput.state(INPUT_ID::UP1).first == 1 && lpInput.state(INPUT_ID::UP1).second == 0)
	{
		menuID--;
		if (menuID < )
		{
			menuID = ;
		}
	}
	if (lpInput.state(INPUT_ID::DOWN1).first == 1 && lpInput.state(INPUT_ID::DOWN1).second == 0)
	{
		menuID++;
		if (menuID > )
		{
			menuID = ;
		}
	}

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