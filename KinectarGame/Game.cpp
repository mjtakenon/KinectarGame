#include "Game.h"


void Game::init()
{
	m_data->musicPath = L"t’†…‰j.wav";
	m_data->scorePath = L"t’†…‰j.score";
	

	m_Kinectar = new Kinectar();
	m_Bar = new Bar(Vec2(50, 100), Vec2(10, 200), Palette::White);
	
	m_Music = new Music(m_data->musicPath, m_Score->getBPM());
	m_Score = new Score(m_data->scorePath, m_Music->getSamplingRate());
	
	m_NotesManager = new NotesManager(m_Score->getNotes());
	m_Music->play();
}

void Game::update()
{
	/*if (Input::MouseL.clicked)
	{
		changeScene(L"Menu", 500);
	}*/

	m_Kinectar->Update();
	m_Bar->Update();

	m_NotesManager->Update(m_Kinectar->getButtonState(),*m_Bar);
}

void Game::draw() const
{
	Println(m_Kinectar->getButtonState().first, m_Kinectar->getButtonState().second);
	m_Bar->Draw();
}