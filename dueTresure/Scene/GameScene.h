#pragma once
#include <Scene/BaseScene.h>
#include <obj/Obj.h>

class GameScene :
	public BaseScene
{
public:
	GameScene();
	~GameScene();
	unique_Base Update(unique_Base own);
private:
	std::vector<sharedObj> _objList;
	std::vector<sharedBG> _bgList;
};

