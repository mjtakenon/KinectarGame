#include "GameManager.h"

GameManager::GameManager()
{
	Window::Resize(1366, 768);


	scene = new SceneManager<String, GameData>(SceneManagerOption::ShowSceneName);

	scene->setFadeColor(Palette::Black);

	scene->add<Title>(L"Title");
	scene->add<Menu>(L"Menu");
	scene->add<Game>(L"Game");

	scene->init(L"Game");
}

GameManager::~GameManager()
{
	delete(scene);
}

void GameManager::Run()
{
	while (System::Update())
	{
		if (!this->Update())
		{
			break;
		}

		this->Draw();
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
	ClearPrint();
	scene->draw();
}
