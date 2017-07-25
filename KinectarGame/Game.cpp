#include "Game.h"


void Game::init()
{
	m_data->musicPath = L"t’†…‰j.wav";
	m_data->scorePath = L"t’†…‰j.data";
	
	m_Kinectar = new Kinectar();


	m_Bar = new Bar(Vec2(50, 200), Vec2(10, 200), Palette::White);
	
	m_Music = new Music(m_data->musicPath);
	m_Score = new Score(m_data->scorePath, m_Music->getSamplingRate());
	
	m_NotesManager = new NotesManager(m_Score->getNotes(), *m_Bar, m_Music->getSamplingRate());
}

void Game::update()
{
	//‹ÈÄ¶ŠJŽn‘O‚¾‚Á‚½‚ç
	if (!m_Music->isPlayed())
	{
		m_Music->play();
	}

	m_Kinectar->Update();
	m_Bar->Update();

	m_NotesManager->Update(m_Kinectar->getButtonState(), m_Music->getPlayingSample(), *m_Bar);
}

void Game::draw() const
{
	Println(m_Kinectar->getButtonState().first, m_Kinectar->getButtonState().second);
	Println((double)m_Music->getPlayingSample()/m_Music->getSamplingRate());
	m_Bar->Draw();
	m_NotesManager->Draw();
}
