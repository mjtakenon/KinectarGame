#include "NotesManager.h"

NotesManager::NotesManager(String scorePath, String musicPath, double bpm, double blank)
{
	m_Notes = list<Note>();
	m_Bar = new Bar(Vec2(100, 100), Vec2(100, 10), Palette::White);
	m_Music = new Music(musicPath, bpm, blank);
}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(pair<vector<int>,vector<int>> input)
{
	//inputからNotesの探索、適切なノーツの削除とか

}

void NotesManager::Draw()
{

}
