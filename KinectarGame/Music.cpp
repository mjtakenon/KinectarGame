#include "Music.h"

Music::Music(String path, double BPM, double Blank)
{
	this->m_Path = path;
	this->m_BPM = BPM;
	m_Sound = new Sound(path);

	if (!m_Sound)
	{
		MessageBox::Show(L"���y�t�@�C����������܂���ł���.");
	}
	m_Sound->getTempo();
}

Music::~Music()
{

}

double Music::getPlayingPosition()
{
	return (m_Sound->streamPosSample()/m_Sound->samplingRate());
}

void Music::play()
{
	m_Sound->play();
}