#include "Title.h"


void Title::init()
{
	font(10);

	m_StartPosition = Vec2(Window::Width() / 3*2, Window::Height() / 3*2);
	m_PracticePosition = Vec2(Window::Width() / 3*2, Window::Height() / 3*2 + 40);
	m_SettingPosition = Vec2(Window::Width() / 3*2, Window::Height() / 3*2 + 80);
	m_ExitPosition = Vec2(Window::Width() / 3*2, Window::Height() / 3*2 + 120);

	m_ButtonSize = Vec2(Window::Width()/3 , 40);

	m_StartButton = new RectButton(m_StartPosition, m_ButtonSize, Palette::White);
	m_PracticeButton = new RectButton(m_PracticePosition, m_ButtonSize, Palette::White);
	m_SettingButton = new RectButton(m_SettingPosition, m_ButtonSize, Palette::Gray);
	m_ExitButton = new RectButton(m_ExitPosition, m_ButtonSize, Palette::White);
}

void Title::update()
{
	if (m_StartButton->isClicked())
	{
		m_data->practiceMode = false;

		m_data->musicPath = L"t’†…‰j.wav";
		m_data->scorePath = L"t’†…‰j.data";

		m_data->string = 6;
		m_data->flet = 5;

		changeScene(L"Game", 500);
	}

	if (m_PracticeButton->isClicked())
	{
		m_data->practiceMode = true;

		m_data->musicPath = L"";
		m_data->scorePath = L"";

		m_data->string = 6;
		m_data->flet = 5;

		changeScene(L"Practice", 500);
	}

	if (m_SettingButton->isClicked())
	{
		changeScene(L"Setting", 500);
	}

	if (m_ExitButton->isClicked())
	{
		System::Exit();
	}
}

void Title::draw() const
{
	m_StartButton->Draw();
	font(L"Start").drawAt(m_StartPosition, Palette::Black);
	m_PracticeButton->Draw();
	font(L"Practice").drawAt(m_PracticePosition, Palette::Black);
	m_SettingButton->Draw();
	font(L"Setting").drawAt(m_SettingPosition, Palette::Black);
	m_ExitButton->Draw();
	font(L"Exit").drawAt(m_ExitPosition, Palette::Black);
}