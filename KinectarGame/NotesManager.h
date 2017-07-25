#pragma once

#include <Siv3D.hpp>
#include <list>
#include <vector>

#include "Note.h"
#include "Bar.h"
#include "HitMarker.h"
#include "HitEffect.h"
#include "PointManager.h"
#include "Score.h"

using namespace std;

class NotesManager
{
public:
	NotesManager(Score* score, vector<HitMarker> hitMarkers, int samplingRate);
	~NotesManager();
	
	void Update(vector<int> input, vector<vector<bool>> pushed, int sample, PointManager* pointmanager);
	void Draw();

private:
	list<Note> m_Notes;

	list<Bar> m_Bars;

	vector<HitMarker> m_HitMarkers;

	list<HitEffect> m_HitEffects;

	int m_SamplingRate;

	int m_VisibleFrame;

	int m_VisibleSample;


	int m_HitSample;

	int m_PerfectSample;
	int m_GoodSample;
};