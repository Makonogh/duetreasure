#include "ResultScene.h"
#include "TitleScene.h"
#include "SceneMng.h"
#include "GameScene.h"
#include "RankScene.h"



ResultScene::ResultScene()
{
	TRACE("ÿªﬁŸƒº∞›ê∂ê¨");
}


ResultScene::~ResultScene()
{

}

unique_Base ResultScene::Update(unique_Base own)
{
	switch (menuID)
	{
		case static_cast<int>(MENU::RANKING) :
			if (SceneCount > 60 && sarada == 1)return std::make_unique<RankScene>();
			break;

		case static_cast<int>(MENU::RESTART) :
			if (SceneCount > 60 && sarada == 1)return std::make_unique<GameScene>();
			break;

		case static_cast<int>(MENU::TITLE) :
			if (SceneCount > 60 && sarada == 1)return std::make_unique<TitleScene>();
			break;

		case static_cast<int>(MENU::EXIT) :
			if (SceneCount > 60 && sarada == 1)lpSceneMng.ExitFlag = true;
			break;

		default:
			break;
	}
	if (lpInput.state(INPUT_ID::SELECT).first == 1 && lpInput.state(INPUT_ID::SELECT).second == 0)
	{
		return std::make_unique<TitleScene>();
	}
	return own;
}
