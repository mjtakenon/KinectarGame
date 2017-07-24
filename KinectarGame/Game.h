#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

#include "Bar.h"
#include "Music.h"
#include "Score.h"
#include "NotesManager.h"
#include "Kinectar.h"

struct Game : SceneManager<String, GameData>::Scene
{
	void init() override;
	
	void update() override;

	void draw() const override;

	NotesManager*	m_NotesManager;
	Bar*	m_Bar;

	Music*	m_Music;
	Score*	m_Score;

	Kinectar* m_Kinectar;
};