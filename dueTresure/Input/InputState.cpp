#include "InputState.h"
#include "_debug/_DebugConOut.h"


InputState::InputState()
{
	for (auto id : INPUT_ID())
	{
		_state.try_emplace(id, KeyPair{ 0,1 });
	}
}

InputState::~InputState()
{
}

const KeyMap & InputState::state(void) const
{
	return _state;
}

const KeyPair & InputState::state(INPUT_ID id) const
{
	static KeyPair defData = KeyPair{ 0,0 };
	try
	{
		return _state.at(id);
	}
	catch (...)
	{
		AST();
		return defData;
	}
}

bool InputState::state(INPUT_ID id, int data)
{
	if (_state.find(id) != _state.end())
	{
		_state[id].first = data;
		return true;
	}
	return false;
}

void InputState::SetOld(void)
{
	for (auto id : INPUT_ID())
	{
		_state[id].second = _state[id].first;
		try
		{
			return;
		}
		catch (...)
		{
			AST();
			_state.emplace(id, KeyPair{ 0,1 });
		}
	}

}
