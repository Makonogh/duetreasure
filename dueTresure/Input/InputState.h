#pragma once
#include <map>
#include "INPUT_ID.h"

using KeyPair = std::pair<int, int>;					// Œã‚ë‚ªold
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:
	InputState();
	virtual ~InputState();
	void Update(void);
	const KeyMap& state(void)const;
	const KeyPair& state(INPUT_ID id)const;
	bool state(INPUT_ID id, int data);
	void SetOld(void);
private:
	KeyMap _state;
};
