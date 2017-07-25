#include "HitEffect.h"

HitEffect::HitEffect(Vec2 position, Vec2 size, Color color) : Object(position)
{
	this->m_Size = size;
	this->m_Color = color;
	this->m_Visible = true;
}

HitEffect::~HitEffect()
{

}

void HitEffect::Update()
{
	if ((int)m_Color.a - 10 <= 0) 
	{
		this->m_Visible = false;
		return;
	}
	
	m_Color.a -= 10;
}

void HitEffect::Draw() const
{
	if (!m_Visible)
	{
		return;
	}

	Rect(m_Position.x, m_Position.y - (m_Size.y / 2), m_Size.x, m_Size.y).draw( { m_Color, Alpha(0), Alpha(0), m_Color });
}