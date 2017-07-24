#include "NotesManager.h"

NotesManager::NotesManager(list<Note> notes)
{
	m_Notes = notes;
}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(pair<vector<int>,vector<int>> input, const Bar bar)
{
	//inputからNotesの探索、適切なノーツの削除、新しいノーツの出現とか
	//音楽とずれてたら調整とかも?→Game.cppの方でやらせるべきかな
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Update();
	}
}

void NotesManager::Draw()
{
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Draw();
	}
}
