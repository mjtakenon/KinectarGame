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

	// シーンのキーの型と、共有データの型を指定
	using Scenes = SceneManager<String, GameData>;
	Scenes* scene;
};
