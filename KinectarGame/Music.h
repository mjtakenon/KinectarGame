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

	//BPM�Œ�
	//�ςƂ���Ȃ�ς̎��ԂƉό�̃e���|��z��ŕێ����� pair<vector<int>,vector<int>>
	double 	m_BPM;
};
