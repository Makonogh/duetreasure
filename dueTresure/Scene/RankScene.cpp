#include "RankScene.h"
#include "TitleScene.h"

RankScene::RankScene()
{
	TRACE("◊›∑›∏ﬁº∞›ê∂ê¨")
}
RankScene::~RankScene()
{

}

unique_Base RankScene::Update(unique_Base own)
{
	if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	{
		return std::make_unique<TitleScene>();
	}
	return own;
}
