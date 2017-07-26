#include "GameManager.h"

GameManager::GameManager()
{
	Window::Resize(1366, 768);
	Window::SetStyle(WindowStyle::Sizeable);

	scene = new SceneManager<String, GameData>();

	scene->setFadeColor(Palette::Black);

	scene->add<Title>(L"Title");
	scene->add<Menu>(L"Menu");
	scene->add<Game>(L"Game");
	scene->add<Game>(L"Practice");

	scene->init(L"Title");
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
