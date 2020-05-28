#pragma once
#include <Scene/BaseScene.h>
#include <vector>

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own);
private:
	MENU menu;
	unique_Base iconDraw;

	std::vector<sharedBG> _bgList;
};

