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
	

	_state[INPUT_ID::LEFT1].first  = CheckHitKey(KEY_INPUT_A);
	_state[INPUT_ID::RIGHT1].first = CheckHitKey(KEY_INPUT_D);
	_state[INPUT_ID::UP1].first    = CheckHitKey(KEY_INPUT_W);
	_state[INPUT_ID::DOWN1].first  = CheckHitKey(KEY_INPUT_S);
	_state[INPUT_ID::LEFT2].first  = CheckHitKey(KEY_INPUT_NUMPAD4);
	_state[INPUT_ID::RIGHT2].first = CheckHitKey(KEY_INPUT_NUMPAD6);
	_state[INPUT_ID::UP2].first    = CheckHitKey(KEY_INPUT_NUMPAD8);
	_state[INPUT_ID::DOWN2].first  = CheckHitKey(KEY_INPUT_NUMPAD5);
	_state[INPUT_ID::BTN_1].first  = CheckHitKey(KEY_INPUT_Q);
	_state[INPUT_ID::BTN_2].first  = CheckHitKey(KEY_INPUT_E);
	_state[INPUT_ID::BTN_3].first  = CheckHitKey(KEY_INPUT_7);
	_state[INPUT_ID::BTN_4].first  = CheckHitKey(KEY_INPUT_9);
	_state[INPUT_ID::START].first  = CheckHitKey(KEY_INPUT_RETURN);
	_state[INPUT_ID::SELECT].first = CheckHitKey(KEY_INPUT_SPACE);

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
