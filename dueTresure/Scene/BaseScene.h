#pragma once
#include <memory>
#include <vector>
#include <_debug/_DebugConOut.h>
#include <bg/Bg.h>
#include <Input/InputState.h>

class BaseScene;

using unique_Base = std::unique_ptr<BaseScene>;

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual unique_Base Update(unique_Base) = 0;
	int SceneCount;
	bool sarada;		//(âºñºÅj
	int menuID;
	int IntervalOffset;
	void SelectPath(void);
};



