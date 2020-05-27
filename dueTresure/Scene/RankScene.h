#pragma once
#include <Scene/BaseScene.h>

class RankScene :
	public BaseScene
{
public:
	RankScene();
	~RankScene();
	unique_Base Update(unique_Base own);
};