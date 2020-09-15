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
	bool CheckHit(Vector2Dbl pos,Vector2Dbl size);
private:
	void Draw();
	void Hide();
	Vector2Dbl sCenter;
	Vector2Dbl sSize;
	std::vector<sharedObj> _objList;
	std::vector<sharedObj> _playerList;
};

