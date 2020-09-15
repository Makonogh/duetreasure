#pragma once
#include "Obj.h"

enum class GIMMIC
{
	FLOOR,				// ��
	HASHIRA,
	BLOCK,
	GOAL,
	GIMMIC_MAX,
};

using GIMMIC_DATA = std::tuple< Vector2Dbl, Vector2Dbl, GIMMIC>;					// <�摜���߁A���W�A����>

class Gimmic :
	public Obj
{
public:
	Gimmic();
	Gimmic(GIMMIC_DATA data);
	void Update();
	void Update(GameScene& data);
	void Draw();
	bool GetJudge();
	~Gimmic();
private:
	Vector2Dbl _startPos;
	GIMMIC _type;
	void Init();
};

