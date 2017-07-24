#pragma once

#include <Siv3D.hpp>

class Music
{
public:
	Music(String path,double BPM);
	~Music();
	
	double	getPlayingPosition();
	double	getBPM() { return m_BPM; };
	int		getSamplingRate() { return m_Sound->samplingRate(); };

	void play();

private:

	String m_Path;
	Sound* m_Sound;

	//BPM固定
	//可変とするなら可変の時間と可変後のテンポを配列で保持かな pair<vector<int>,vector<int>>
	double 	m_BPM;
};
