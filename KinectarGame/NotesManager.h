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
	
	void Update(vector<int> input, int sample);
	void Draw();

private:
	list<Note> m_Notes;

	vector<Bar> m_Bars;
	

	int m_SamplingRate;

	int m_VisibleFrame;

	int m_VisibleSample;


	int m_HitSample;

	int m_PerfectSample;
	int m_GoodSample;
};