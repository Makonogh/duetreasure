#include "Obj.h"


Obj::Obj()
{
}

Obj::~Obj()
{
}

bool Obj::SetAnim(const STATE state, AnimVector & data)
{
	return (_animMap.try_emplace(state, std::move(data))).second;
}
