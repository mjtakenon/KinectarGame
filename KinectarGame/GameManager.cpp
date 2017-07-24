#include "GameManager.h"

GameManager::GameManager()
{
	scene = new SceneManager<String, GameData>(SceneManagerOption::ShowSceneName);

	//SceneManagerOption::ShowSceneName を外せばシーン名のデバッグ表示は消える
	//MyApp manager;

	// フェードイン・アウト時の色
	scene->setFadeColor(Palette::Black);

	// シーンを設定
	scene->add<Title>(L"Title");
	scene->add<Menu>(L"Menu");
	scene->add<Game>(L"Game");

	scene->init(L"Title");

}

GameManager::~GameManager()
{

}

void GameManager::Run()
{
	while (System::Update())
	{
		if (!this->Update())
		{
			break;
		}
	}
}

bool GameManager::Update()
{
	if (!scene->update())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameManager::Draw()
{
	scene->draw();
}
