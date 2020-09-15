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
	NORMAL1,		// PL1通常状態
	DASH1,			// PL1右ダッシュ
	REDASH1,		// PL1左ダッシュ
	JUMP1,			// PL1ジャンプ
	NORMAL2,		// PL2通常状態
	DASH2,			// PL2右ダッシュ
	REDASH2,		// PL2左ダッシュ
	JUMP2,			// PL2ジャンプ
	MAX
};

enum class OBJ_DATA
{
	POS,
	SIZE,
	TYPE,
	MAX
};

using AnimVector = std::vector<std::pair<int, unsigned int>>;					// ｺﾏとﾌﾚｰﾑ
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
	bool SetAnim(const STATE state, AnimVector& data);	// アニメーションのセット

	Vector2Dbl GetPos();
	Vector2Dbl GetSize();
	int PlayerCount;									// プレイヤー用アニメーションフレーム
	unsigned int _animCount;							// 見出しから何回ﾙｰﾌﾟしてるか
	unsigned int _animFrame;							// なんﾌﾚｰﾑか
	virtual bool GetJudge();
private:
	std::map<STATE, AnimVector>_animMap;
	
protected:
	Vector2Dbl _pos;									// 座標
	Vector2Dbl _size;									// サイズ
	Vector2Dbl _velocity;								// 加速度
	STATE _state;										// 状態
	bool _judge;			// trueなら消える
};

