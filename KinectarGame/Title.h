#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

struct Title : SceneManager<String, GameData>
{
	void init();

	void update();

	void draw() const;
};