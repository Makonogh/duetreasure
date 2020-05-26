#include "BaseScene.h"

BaseScene::BaseScene()
{
}


BaseScene::~BaseScene()
{
}

void BaseScene::SelectPath(void)
{
	if (sarada == 0)
	{
		sarada = 1;
		SceneCount = 0;
	}
	else sarada = 0;
}