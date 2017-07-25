#include "Game.h"


void Game::init()
{
	m_data->musicPath = L"t’†…‰j.wav";
	m_data->scorePath = L"t’†…‰j.data";
	
	m_data->string = 6;
	m_data->flet = 5;

	m_StringMargin = 5;
	
	m_HitMarkerSize = Vec2(20,250);
	m_HitMarkerPosition = Vec2(100, 100);

	m_Kinectar = new Kinectar();

	m_HitMarkers = vector<HitMarker>();
	for (auto n = 0; n < m_data->string; n++)
	{
		Vec2 pos = Vec2(m_HitMarkerPosition.x, m_HitMarkerPosition.y + (m_HitMarkerSize.y / m_data->string) * n + n*m_StringMargin);
		Vec2 size = Vec2(m_HitMarkerSize.x, m_HitMarkerSize.y / m_data->string);
		m_HitMarkers.push_back(HitMarker(pos, size, Palette::White));
	}
	
	m_GuitarStrings = vector<GuitarString>();

	for (auto n = 0; n < m_data->string; n++)
	{
		Vec2 pos = Vec2(10, m_HitMarkers[n].getPosition().y);
		Vec2 size = Vec2(Window::Width(), 2);
		m_GuitarStrings.push_back(GuitarString(pos, size, Palette::White));
	}

	m_Music = new Music(m_data->musicPath);
	m_Score = new Score(m_data->scorePath, m_Music->getSamplingRate());
	
	m_NotesManager = new NotesManager(m_Score, m_HitMarkers, m_Music->getSamplingRate());

	m_PointManager = new PointManager();

	m_EndLine = Vec2(m_GuitarStrings.begin()->getPosition());

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
	for (auto n = 0; n < m_HitMarkers.size(); n++)
	{
		vector<bool> state = vector<bool>(5);
		for (auto m = 0; m < state.size(); m++)
		{
			state[m] = states[m][n];
		}
		m_HitMarkers[n].Update(state);
	}

	for (auto n = 0; n < m_GuitarStrings.size(); n++)
	{
		m_GuitarStrings[n].Update(m_Kinectar->getSoundTime()[n]);
	}

	m_NotesManager->Update(m_Kinectar->getSoundTime(), m_Kinectar->getPushedState(), m_Music->getPlayingSample(), m_PointManager);
	m_PointManager->Update();
}

void Game::draw() const
{
	Println((double)m_Music->getPlayingSample()/m_Music->getSamplingRate());
	Println(m_Kinectar->getSoundTime());

	m_Kinectar->Draw();

	//endline
	Rect(m_EndLine.x, m_EndLine.y, 5, (m_HitMarkerSize.y / m_data->string) * (m_data->string-1) + (m_data->string-1) * m_StringMargin).draw(Palette::White);
	Rect(m_EndLine.x+10, m_EndLine.y, 2, (m_HitMarkerSize.y / m_data->string) * (m_data->string - 1) + (m_data->string - 1) * m_StringMargin).draw(Palette::White);

	for (auto n = 0; n < m_HitMarkers.size(); n++)
	{
		m_HitMarkers[n].Draw();
	}

	for (auto n = 0; n < m_GuitarStrings.size(); n++)
	{
		m_GuitarStrings[n].Draw();
	}

	m_PointManager->Draw();
	m_NotesManager->Draw();
}
