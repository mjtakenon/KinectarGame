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

	//BPM�Œ�
	//�ςƂ���Ȃ�ς̎��ԂƉό�̃e���|��z��ŕێ����Ȃ�pair<vector<int>,vector<int>>
	double 	m_BPM;
	double	m_Blank;
};
