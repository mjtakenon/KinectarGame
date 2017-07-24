#pragma once

#include <Siv3D.hpp>
#include <list>
#include <vector>

#include "Note.h"
#include "Bar.h"

using namespace std;

class NotesManager
{
public:
	NotesManager(list<Note> notes);
	~NotesManager();
	
	void Update(pair<vector<int>,vector<int>> input,const Bar bar);
	void Draw();

private:
	list<Note> m_Notes;
};