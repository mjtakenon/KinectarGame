#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

struct Title : SceneManager<String, GameData>::Scene
{
	void init() override;

	void update() override;

	void draw() const override;
};