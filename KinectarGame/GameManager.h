#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

#include "Title.h"
#include "Menu.h"
#include "Game.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Run();

private:

	bool Update();
	void Draw();

	using Scenes = SceneManager<String, GameData>;
	Scenes* scene;
};
