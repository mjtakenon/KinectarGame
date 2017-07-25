#include "Note.h"

Note::Note(Vec2 position, int string, int flet,int sample, Vec2 size, Vec2 speed) : Object(position)
{
	m_String = string;
	m_Flet = flet;
	m_Sample = sample;
	m_Size = size;
	m_Speed = speed;
	m_font((size.x+size.y/2));

	m_isEnable = false;
	m_isVisible = false;

	switch (flet)
	{
	case 0:
		m_Color = Palette::White;
		break;
	case 1:
		m_Color = Palette::Red;
		break;
	case 2:
		m_Color = Palette::Orange;
		break;
	case 3:
		m_Color = Palette::Yellow;
		break;
	case 4:
		m_Color = Palette::Green;
		break;
	case 5:
		m_Color = Palette::Blue;
		break;
	}
}

Note::~Note()
{

}

void Note::Update(double sample, int samplingRate, Vec2 barPosition, int hitSample, int visibleSample)
{
	//Visible‚Å•\Ž¦
	//Enable‚Åhit‰Â”\

	if (sample - visibleSample <= m_Sample)
	{
		m_isVisible = true;
	}

	if (sample - hitSample <= m_Sample)
	{
		m_isEnable = true;
	}

	if (!m_isEnable)
	{
		return;
	}

	m_Position.x = barPosition.x + (m_Speed.x*((m_Sample - sample) / samplingRate * 60));
}

void Note::Draw()
{
	if (!m_isVisible)
	{
		return;
	}

	Ellipse(m_Position, m_Size).draw(m_Color);
	m_font(m_Flet).drawCenter(m_Position, Palette::Black);
}

