#pragma once

#include <Siv3D.hpp>

class Music
{
public:
	Music(String path,double BPM, double Blank);
	~Music();
	
	double getPlayingPosition();
	int getBPM() { return m_BPM; };

	void play();

private:

	String m_Path;
	Sound* m_Sound;

	//BPM固定
	//可変とするなら可変の時間と可変後のテンポを配列で保持かなぁpair<vector<int>,vector<int>>
	double 	m_BPM;
	double	m_Blank;
};
