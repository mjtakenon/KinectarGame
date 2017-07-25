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
	NotesManager(list<Note> notes,vector<Bar> bars, int samplingRate);
	~NotesManager();
	
	void Update(pair<vector<int>,vector<int>> input, int sample);
	void Draw();

private:
	list<Note> m_Notes;

	int m_SamplingRate;

	int m_PrepareFrame;

	int m_VisibleSample;
	int m_HitSample;

	vector<Bar> m_Bars;

};