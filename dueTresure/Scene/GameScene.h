#pragma once
#include <Scene/BaseScene.h>

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base Update(unique_Base own);
};

