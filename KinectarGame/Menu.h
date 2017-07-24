#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

struct Menu : SceneManager<String, GameData>
{
	void update();

	void init();

	void draw() const;
};