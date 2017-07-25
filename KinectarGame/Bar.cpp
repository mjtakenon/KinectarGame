#include "Bar.h"

Bar::Bar(Vec2 position, Vec2 size, Color color) : Object(position)
{
	this->m_Size = size;
	this->m_Color = color;
}

Bar::~Bar()
{

}

void Bar::Update()
{

}

void Bar::Draw()
{
	Rect(m_Position.x - (m_Size.x / 2), m_Position.y - (m_Size.y / 2), m_Size.x, m_Size.y).draw(m_Color);
}