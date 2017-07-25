#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"

#include "HitMarker.h"
#include "GuitarString.h"
#include "Music.h"
#include "Score.h"
#include "NotesManager.h"
#include "PointManager.h"
#include "Kinectar.h"

struct Game : SceneManager<String, GameData>::Scene
{
	void init() override;
	
	void update() override;

	void draw() const override;

	NotesManager*	m_NotesManager;
	PointManager* m_PointManager;

	vector<HitMarker>	m_HitMarkers;
	vector<GuitarString> m_GuitarStrings;

	int m_StringMargin;

	Music*	m_Music;
	Score*	m_Score;

	Kinectar* m_Kinectar;

	Vec2 m_HitMarkerSize;
	Vec2 m_HitMarkerPosition;

	Vec2 m_EndLine;
};