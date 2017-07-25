#include "Bar.h"

Bar::Bar(Vec2 position, Vec2 size, Color color) : Object(position)
{
	this->m_Size = size;
	this->m_Color = color;
}

Bar::~Bar()
{

}

void Bar::Update(vector<bool> buttonState)
{
	int state = 0;

	for (auto n = 0; n < buttonState.size(); n++)
	{
		if (buttonState[n])
		{
			state = n+1;
		}
	}

	switch (state)
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
	default:
		m_Color = Palette::White;
		break;
	}

}

void Bar::Draw() const
{
	Rect(m_Position.x - (m_Size.x / 2), m_Position.y - (m_Size.y / 2), m_Size.x, m_Size.y).draw(m_Color);
	Rect(m_Position.x, m_Position.y - (m_Size.y / 2), 1, m_Size.y).draw(Palette::Black);
}