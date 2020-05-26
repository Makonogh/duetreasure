#pragma once
#include "Obj.h"
class Player :
	public Obj
{
public:
	Player();
	~Player();
	void Update(sharedObj& list) override;
private:
	void Init(void);
};

