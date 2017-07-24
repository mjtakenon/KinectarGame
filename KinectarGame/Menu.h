#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

struct Menu : SceneManager<String, GameData>::Scene
{
	void init() override;

	void update() override;

	void draw() const override;
};