#include "Game.h"


void Game::init()
{
	m_data->musicPath = L"t’†…‰j.wav";
	m_data->scorePath = L"t’†…‰j.data";
	
	m_data->string = 6;
	m_data->flet = 5;
	
	m_BarSize = Vec2(20,250);
	m_BarPosition = Vec2(100, 100);

	m_Kinectar = new Kinectar();

	m_Bars = vector<Bar>();
	for (auto n = 0; n < m_data->string; n++)
	{
		Vec2 pos = Vec2(m_BarPosition.x, m_BarPosition.y + (m_BarSize.y / m_data->string) * n + n*5);
		Vec2 size = Vec2(m_BarSize.x, m_BarSize.y / m_data->string);
		m_Bars.push_back(Bar(pos, size, Palette::White));
	}
	
	m_Music = new Music(m_data->musicPath);
	m_Score = new Score(m_data->scorePath, m_Music->getSamplingRate());
	
	m_NotesManager = new NotesManager(m_Score->getNotes(), m_Bars, m_Music->getSamplingRate());
}

void Game::update()
{
	//‹ÈÄ¶ŠJŽn‘O‚¾‚Á‚½‚ç
	if (!m_Music->isPlayed())
	{
		m_Music->play();
	}

	m_Kinectar->Update();
	
	vector<vector<bool>> states = m_Kinectar->getPushedState();
	for (auto n = 0; n < m_Bars.size(); n++)
	{
		vector<bool> state = vector<bool>(5);
		for (auto m = 0; m < state.size(); m++)
		{
			state[m] = states[m][n];
		}
		m_Bars[n].Update(state);
	}

	m_NotesManager->Update(m_Kinectar->getButtonState(), m_Music->getPlayingSample());

}

void Game::draw() const
{
	Println(m_Kinectar->getButtonState().first, m_Kinectar->getButtonState().second);
	Println(m_Kinectar->getPushedState());
	Println((double)m_Music->getPlayingSample()/m_Music->getSamplingRate());

	for (auto n = 0; n < m_Bars.size(); n++)
	{
		m_Bars[n].Draw();
	}

	m_NotesManager->Draw();
}
