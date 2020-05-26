#pragma once
#include <Scene/BaseScene.h>

enum class R_MENU {
	RANKING,
	RESTART,
	TITLE,
	EXIT,
	MAX
};

class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	unique_Base Update(unique_Base own);


};

