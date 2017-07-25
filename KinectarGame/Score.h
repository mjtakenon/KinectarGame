#pragma once

#include <list>

#include <Siv3D.hpp>

#include "Note.h"

using namespace std;

//譜面をファイルから読み込んでNotesManagerに渡す
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
	//BPM固定
	//可変とするなら可変の時間と可変後のテンポを配列で保持かな pair<vector<int>,vector<int>>
	double m_BPM;
	double m_Blank;
};