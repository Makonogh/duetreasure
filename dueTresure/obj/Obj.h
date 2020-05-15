#pragma once
#include <vector>
#include <memory>
#include <map>
#include "common/Vector2.h"
#include "Scene\SceneMng.h"

class Obj;

enum class STATE
{
	NORMAL,		// �ʏ���
	JUMP,		// �W�����v
	FALL,		// �]�|
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;					// �ς��ڰ�
using sharedObj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual ~Obj();

	bool SetAnim(const STATE state, AnimVector& data);	// �A�j���[�V�����̃Z�b�g
	Vector2Dbl _pos;									// ���W
	Vector2Dbl _size;									// �T�C�Y
	STATE _state;										// ���
	int PlayerCount;									// �v���C���[�p�A�j���[�V�����t���[��
private:
	std::map<STATE, AnimVector>_animMap;
};

