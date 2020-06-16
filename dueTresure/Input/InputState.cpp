#include "InputState.h"
#include "_debug/_DebugConOut.h"
#include "DxLib.h"


InputState* InputState::sInstance = nullptr;

InputState::InputState()
{
	for (auto id : INPUT_ID())
	{
		_state.try_emplace(id, KeyPair{ 0,0 });
	}
}

InputState::~InputState()
{
}

void InputState::Update(void)
{
	InputState::SetOld();
	for (auto id : INPUT_ID())
	{
		_state[id].first = 0;
	}
	
	if ((CheckHitKey(KEY_INPUT_A)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)
	{
		_state[INPUT_ID::LEFT1].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_D)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)
	{
		_state[INPUT_ID::RIGHT1].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_W)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)
	{
		_state[INPUT_ID::UP1].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_S)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)
	{
		_state[INPUT_ID::DOWN1].first = 1;
	}
	
	if ((CheckHitKey(KEY_INPUT_NUMPAD4)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_LEFT)
	{
		_state[INPUT_ID::LEFT2].first = 1;
	}
	
	if ((CheckHitKey(KEY_INPUT_NUMPAD6)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_RIGHT)
	{
		_state[INPUT_ID::RIGHT2].first = 1;
	}
	
	if ((CheckHitKey(KEY_INPUT_NUMPAD8)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_UP)
	{
		_state[INPUT_ID::UP2].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_NUMPAD5)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_DOWN)
	{
		_state[INPUT_ID::DOWN2].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_Q)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)
	{
		_state[INPUT_ID::BTN_1].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_E)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_2)
	{
		_state[INPUT_ID::BTN_2].first = 1;
	}
	
	if ((CheckHitKey(KEY_INPUT_NUMPAD7)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_1)
	{
		_state[INPUT_ID::BTN_3].first = 1;
	}
	
	if ((CheckHitKey(KEY_INPUT_NUMPAD9)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_2)
	{
		_state[INPUT_ID::BTN_4].first = 1;
	}
	
	if ((CheckHitKey(KEY_INPUT_SPACE)) || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_10)
	{
		_state[INPUT_ID::SELECT].first = 1;
	}

	if ((CheckHitKey(KEY_INPUT_RETURN)) || GetJoypadInputState(DX_INPUT_PAD2) & PAD_INPUT_10)
	{
		_state[INPUT_ID::START].first = 1;
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
	}

}
