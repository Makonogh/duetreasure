#pragma once
#include <Scene/BaseScene.h>
#include <vector>

enum T_MENU 
{
	T_GAMESTART,
	T_HOW_TO,
	T_RANKING,
	T_EXIT,
};

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own);
private:
	T_MENU menu;
	unique_Base iconDraw;
	std::vector<sharedBG> _bgList;
};

