#pragma once

#include <Siv3D.hpp>
#include <list>
#include <vector>

#include "Note.h"
#include "Bar.h"
#include "Music.h"

using namespace std;

class NotesManager
{
public:
	NotesManager(String scorePath, String musicPath, double bpm, double blank);
	~NotesManager();
	
	void Update(pair<vector<int>,vector<int>> input);
	void Draw();

private:
	list<Note> m_Notes;

	Bar* m_Bar;

	Music* m_Music;
	Score* m_Score;

};