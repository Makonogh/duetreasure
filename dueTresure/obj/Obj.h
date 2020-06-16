#pragma once
#include <vector>
#include <memory>
#include <map>
#include "common/Vector2.h"
#include "Scene\SceneMng.h"

class Obj;

enum class STATE
{
	NORMAL1,		// PL1通常状態
	DASH1,			// PL1ジャンプ
	NORMAL2,		// PL2通常状態
	DASH2,			// PL2ジャンプ
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;					// ｺﾏとﾌﾚｰﾑ
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
	bool SetAnim(const STATE state, AnimVector& data);	// アニメーションのセット
	int PlayerCount;									// プレイヤー用アニメーションフレーム
	unsigned int _animCount;							// 見出しから何回ﾙｰﾌﾟしてるか
	unsigned int _animFrame;							// なんﾌﾚｰﾑか
private:
	std::map<STATE, AnimVector>_animMap;
protected:
	Vector2Dbl _pos;									// 座標
	Vector2Dbl _size;									// サイズ
	STATE _state;										// 状態
};

