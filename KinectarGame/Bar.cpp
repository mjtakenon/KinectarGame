#include "Bar.h"

Bar::Bar(Vec2 position, Vec2 size, Color color) : Object(position)
{
	m_Size = size;
	m_Color = color;
}

Bar::~Bar()
{

}