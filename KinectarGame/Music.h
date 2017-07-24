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

	//BPMŒÅ’è
	//‰Â•Ï‚Æ‚·‚é‚È‚ç‰Â•Ï‚ÌŠÔ‚Æ‰Â•ÏŒã‚Ìƒeƒ“ƒ|‚ğ”z—ñ‚Å•Û‚©‚È pair<vector<int>,vector<int>>
	double 	m_BPM;
};
