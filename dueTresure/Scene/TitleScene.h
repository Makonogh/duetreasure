#pragma once
#include <Scene/BaseScene.h>
#include <vector>

enum class MENU {
	GAMESTART,
	HOW_TO,
	RANKING,
	EXIT,
	MAX
};

class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();
	unique_Base Update(unique_Base own);
private:
	int menuID;
	int WKeyOld;
	int WKeyNew;
	int SKeyOld;
	int SKeyNew;
};

