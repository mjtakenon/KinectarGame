#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

struct Game : SceneManager<String, GameData>::Scene
{
	void init(); 
	
	void update();

	void draw() const;

	
	int	m_BPM;
	
	
};