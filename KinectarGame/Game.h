#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

#include "Bar.h"
#include "GuitarString.h"
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
	
	vector<Bar>	m_Bars;
	vector<GuitarString> m_GuitarStrings;

	Music*	m_Music;
	Score*	m_Score;

	Kinectar* m_Kinectar;

	Vec2 m_BarSize;
	Vec2 m_BarPosition;
};