#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

struct Game : SceneManager<String, GameData>
{
	void update();

	void init();

	void draw() const;
};