#include "Music.h"

Music::Music(String path)
{
	this->m_Path = path;
	m_Sound = new Sound(path);

	if (!m_Sound)
	{
		MessageBox::Show(L"音楽ファイルが見つかりませんでした.");
	}
	m_Sound->getTempo();
	m_isPlayed = false;
}

Music::~Music()
{

}

/*double Music::getPlayingPosition()
{
	return (m_Sound->streamPosSample()/m_Sound->samplingRate());
}*/

int Music::getPlayingSample()
{
	return static_cast<int32>(m_Sound->streamPosSample());
}

void Music::play()
{
	m_Sound->play();
	m_isPlayed = true;
}