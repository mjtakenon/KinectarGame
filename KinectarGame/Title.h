#pragma once

#include <Siv3d.hpp>
#include <HamFramework.hpp>

#include "GameData.h"
#include "RectButton.h"

struct Title : SceneManager<String, GameData>::Scene
{
	void init() override;

	void update() override;

	void draw() const override;

	Font font;

	Vec2 m_ButtonSize;

	Vec2 m_StartPosition;
	Vec2 m_PracticePosition;
	Vec2 m_SettingPosition;
	Vec2 m_ExitPosition;

	RectButton* m_StartButton;
	RectButton* m_PracticeButton;
	RectButton* m_SettingButton;
	RectButton* m_ExitButton;
};