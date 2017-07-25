#pragma once

#include <Siv3D.hpp>

class Music
{
public:
	Music(String path);
	~Music();
	
	int		getPlayingSample();
	int		getSamplingRate() { return m_Sound->samplingRate(); };
	bool	isPlayed() { return m_isPlayed; };
	void	play();

private:

	String	m_Path;
	Sound*	m_Sound;
	bool	m_isPlayed;
};
