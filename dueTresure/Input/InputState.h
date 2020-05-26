#pragma once
#include <map>
#include "INPUT_ID.h"

#define lpInput InputState::GetInstance()

using KeyPair = std::pair<int, int>;					// Œã‚ë‚ªold
using KeyMap = std::map<INPUT_ID, KeyPair>;

class InputState
{
public:

	static InputState &GetInstance(void)
	{
		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new InputState();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	};

	InputState();
	~InputState();
	void Update(void);
	const KeyMap& state(void)const;
	const KeyPair& state(INPUT_ID id)const;
	bool state(INPUT_ID id, int data);
private:
	void SetOld(void);
	static InputState* sInstance;
	KeyMap _state;
};
