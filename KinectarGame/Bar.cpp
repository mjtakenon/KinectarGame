#include "Bar.h"

Bar::Bar(Vec2 position, Vec2 size, Vec2 speed, Vec2 erasePosition, Color color, int hitSample) : Object(position)
{
	this->m_Size = size;
	this->m_Speed = speed;
	this->m_Color = color;
	this->m_ErasePosition = erasePosition;
	this->m_HitSample = hitSample;

	this->m_Visible = false;
}

Bar::~Bar()
{

}

void Bar::Update(double currentSample, int samplingRate, Vec2 hitMarkerPosition)
{
	if (m_ErasePosition.x >= m_Position.x)
	{
		m_Visible = false;
	}

	if (m_Position.x <= Window::Width())
	{
		m_Visible = true;
	}

	m_Position.x = hitMarkerPosition.x + (m_Speed.x*((m_HitSample - currentSample) / samplingRate * 60));
}

void Bar::Draw() const
{
	if (!m_Visible)
	{
		return;
	}

	Rect(m_Position.x - (m_Size.x / 2), m_Position.y, m_Size.x, m_Size.y).draw(m_Color);
}

