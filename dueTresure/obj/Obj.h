#pragma once
#include <vector>
#include <memory>
#include <map>
#include "common/Vector2.h"
#include "Scene/SceneMng.h"

class Obj;
class GameScene;
enum class STATE
{
	NORMAL1,		// PL1�ʏ���
	DASH1,			// PL1�E�_�b�V��
	REDASH1,		// PL1���_�b�V��
	JUMP1,			// PL1�W�����v
	NORMAL2,		// PL2�ʏ���
	DASH2,			// PL2�E�_�b�V��
	REDASH2,		// PL2���_�b�V��
	JUMP2,			// PL2�W�����v
	MAX
};

enum class OBJ_DATA
{
	POS,
	SIZE,
	TYPE,
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;					// �ς��ڰ�
using sharedObj = std::shared_ptr<Obj>;

class Obj
{
public:
	Obj();
	virtual ~Obj();
	virtual void Update(GameScene& data);
	virtual void Update();
	void Draw(void);
	void Draw(int id);
	bool SetAnim(const STATE state, AnimVector& data);	// �A�j���[�V�����̃Z�b�g

	Vector2Dbl GetPos();
	Vector2Dbl GetSize();
	int PlayerCount;									// �v���C���[�p�A�j���[�V�����t���[��
	unsigned int _animCount;							// ���o�����牽��ٰ�߂��Ă邩
	unsigned int _animFrame;							// �Ȃ��ڰт�
	virtual bool GetJudge();
private:
	std::map<STATE, AnimVector>_animMap;
	
protected:
	Vector2Dbl _pos;									// ���W
	Vector2Dbl _size;									// �T�C�Y
	Vector2Dbl _velocity;								// �����x
	STATE _state;										// ���
	bool _judge;			// true�Ȃ������
};

