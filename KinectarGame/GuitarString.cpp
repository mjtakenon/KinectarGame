#include "GuitarString.h"

GuitarString::GuitarString(Vec2 position, Vec2 size, Color color) : Object(position)
{
	this->m_Size = size;
	this->m_Color = color;
}

GuitarString::~GuitarString()
{

}

void GuitarString::Update(int soundTime)
{
	if (soundTime == 0 || soundTime * 10 > 255)
	{
		m_Color = Palette::White;
	}
	else
	{
		m_Color = Color(255, 255, 0 + soundTime * 10);
	}
}

void GuitarString::Draw() const
{
	Rect(m_Position.x, m_Position.y - (m_Size.y / 2), m_Size.x, m_Size.y).draw(m_Color);
}