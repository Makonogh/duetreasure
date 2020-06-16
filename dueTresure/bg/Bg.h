#pragma once
#include <string>
#include "common/Vector2.h"
#include <memory>


class Bg;
using sharedBG = std::shared_ptr<Bg>;


enum class BG_STATE
{
	IMAGE,
	POS,
	SIZE,
};

class Bg
{
public:
	Bg();
	virtual void Update();
	virtual void Scroll();
	void Draw(void);
	virtual ~Bg();
	Vector2Dbl _pos;
private:

	unsigned int _animFrame;							// なんﾌﾚｰﾑか
	unsigned int _animCount;							// 見出しから何回ﾙｰﾌﾟしてるか
protected:
	std::string image;									// 各ｸﾗｽでのｲﾒｰｼﾞの名前
	Vector2Dbl _size;
	int _zOrder;										// 描画優先度
};
