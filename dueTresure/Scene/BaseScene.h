#pragma once
#include <memory>
#include <vector>
#include <_debug/_DebugConOut.h>
#include <bg/Bg.h>
#include <Input/InputState.h>

//enum class MENU 
//{
//	GAMESTART,
//	HOW_TO,
//	RANKING,
//	EXIT,
//	BACK,
//	RESTART,
//	TITLE,
//	MAX
//};


class BaseScene;

using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_Base Update(unique_Base) = 0;
	int SceneCount;
	bool SelectCheck;		//(�����j
	int menuID;
	int IntervalOffset;
	void SelectPath();
	//std::vector<MENU> _menuList;

};



