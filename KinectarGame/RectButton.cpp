#include "RectButton.h"

RectButton::RectButton(Vec2 position, Vec2 size, Color color) : Object(position)
{
	m_Size = size;
	m_Color = color;
	m_Rect = Rect(m_Position.x-m_Size.x/2, m_Position.y-m_Size.y/2, m_Size.x, m_Size.y);
}

RectButton::~RectButton() {}

void RectButton::Update() {}

void RectButton::Draw() const
{
	m_Rect.draw(m_Color); 
}
