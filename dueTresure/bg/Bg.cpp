#include "Bg.h"
#include "DxLib.h"
#include "common\ImgMng.h"
#include "Scene\SceneMng.h"


Bg::Bg()
{
}

void Bg::Update()
{
}

void Bg::Scroll()
{
}

bool Bg::GetJudge()
{
	return false;
}

void Bg::Draw(void)
{
	lpSceneMng.AddDrawQue({ IMAGE_ID(image)[0],_pos.x,_pos.y ,0.0,INT_MAX, LAYER::BG });
}


Bg::~Bg()
{
}
