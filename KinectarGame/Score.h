#pragma once

#include <list>

#include <Siv3D.hpp>

#include "Note.h"

using namespace std;

//•ˆ–Ê‚ğƒtƒ@ƒCƒ‹‚©‚ç“Ç‚İ‚ñ‚ÅNotesManager‚É“n‚·
class Score
{
public:
	Score(String path, int SamplingRate);
	~Score();

	list<Note> getNotes() { return m_Notes; };
	double getBPM() { return m_BPM; };
	double getBlank() { return m_Blank; };

private:
	String m_Path;
	list<Note> m_Notes;
	double m_BPM;
	double m_Blank;
};