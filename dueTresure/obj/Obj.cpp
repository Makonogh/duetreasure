#include "Obj.h"


Obj::Obj()
{
}

Obj::~Obj()
{
}

void Obj::Update(sharedObj & list)
{
}

void Obj::Update()
{
}

bool Obj::SetAnim(const STATE state, AnimVector & data)
{
	return (_animMap.try_emplace(state, std::move(data))).second;
}
