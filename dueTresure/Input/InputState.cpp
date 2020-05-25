#include "InputState.h"
#include "_debug/_DebugConOut.h"
#include "DxLib.h"


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

void InputState::Update(void)
{
	InputState::SetOld();

	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		_state[INPUT_ID::LEFT1].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		_state[INPUT_ID::RIGHT1].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		_state[INPUT_ID::UP1].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		_state[INPUT_ID::DOWN1].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_NUMPAD4) == 1)
	{
		_state[INPUT_ID::LEFT2].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_NUMPAD6) == 1)
	{
		_state[INPUT_ID::RIGHT2].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_NUMPAD8) == 1)
	{
		_state[INPUT_ID::UP2].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_NUMPAD5) == 1)
	{
		_state[INPUT_ID::DOWN2].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_Q) == 1)
	{
		_state[INPUT_ID::BTN_1].first = 1;
	}
	
	if (CheckHitKey(KEY_INPUT_E) == 1)
	{
		_state[INPUT_ID::BTN_2].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_7) == 1)
	{
		_state[INPUT_ID::BTN_3].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_9) == 1)
	{
		_state[INPUT_ID::BTN_4].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		_state[INPUT_ID::START].first = 1;
	}

	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		_state[INPUT_ID::SELECT].first = 1;
	}
}

const KeyMap & InputState::state(void) const
{
	return _state;
}

const KeyPair & InputState::state(INPUT_ID id) const
{
	static KeyPair defData = { 0,0 };
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
		_state[id].first = 0;
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
