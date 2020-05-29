#pragma once
#include <Scene/BaseScene.h>

enum R_MENU
{
	R_RANKING,
	R_RESTART,
	R_TITLE,
	R_EXIT,
	MAX
};

class ResultScene :
	public BaseScene
{
public:
	ResultScene();
	~ResultScene();
	unique_Base Update(unique_Base own);
	std::vector<sharedBG> _bgList;
};

