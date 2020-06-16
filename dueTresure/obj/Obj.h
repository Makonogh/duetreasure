#pragma once
#include <vector>
#include <memory>
#include <map>
#include "common/Vector2.h"
#include "Scene\SceneMng.h"

class Obj;

enum class STATE
{
	NORMAL1,		// PL1�ʏ���
	DASH1,			// PL1�W�����v
	NORMAL2,		// PL2�ʏ���
	DASH2,			// PL2�W�����v
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;					// �ς��ڰ�
using sharedObj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Update(sharedObj& list);
	virtual void Update();
	void Draw(void);
	void Draw(int id);
	bool SetAnim(const STATE state, AnimVector& data);	// �A�j���[�V�����̃Z�b�g
	int PlayerCount;									// �v���C���[�p�A�j���[�V�����t���[��
	unsigned int _animCount;							// ���o�����牽��ٰ�߂��Ă邩
	unsigned int _animFrame;							// �Ȃ��ڰт�
private:
	std::map<STATE, AnimVector>_animMap;
protected:
	Vector2Dbl _pos;									// ���W
	Vector2Dbl _size;									// �T�C�Y
	STATE _state;										// ���
};

