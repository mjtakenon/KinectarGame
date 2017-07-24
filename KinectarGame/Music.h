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

	//BPMŒÅ’è
	//‰Â•Ï‚Æ‚·‚é‚È‚ç‰Â•Ï‚ÌŠÔ‚Æ‰Â•ÏŒã‚Ìƒeƒ“ƒ|‚ğ”z—ñ‚Å•Û‚©‚È‚Ÿpair<vector<int>,vector<int>>
	double 	m_BPM;
	double	m_Blank;
};
