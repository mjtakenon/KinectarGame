#pragma once

#include <Siv3D.hpp>
#include <list>
#include <vector>

#include "Note.h"
#include "HitMarker.h"
#include "HitEffect.h"
#include "PointManager.h"

using namespace std;

class NotesManager
{
public:
	NotesManager(list<Note> notes,vector<HitMarker> hitMarkers, int samplingRate);
	~NotesManager();
	
	void Update(vector<int> input, vector<vector<bool>> pushed, int sample, PointManager* pointmanager);
	void Draw();

private:
	list<Note> m_Notes;

	vector<HitMarker> m_HitMarkers;

	list<HitEffect> m_HitEffects;

	int m_SamplingRate;

	int m_VisibleFrame;

	int m_VisibleSample;


	int m_HitSample;

	int m_PerfectSample;
	int m_GoodSample;
};