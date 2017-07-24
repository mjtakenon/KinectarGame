#include "Note.h"

Note::Note(Vec2 position, int string, int flet, Vec2 size, Vec2 speed) : Object(position)
{
	this->m_String = string;
	this->m_Flet = flet;
	this->m_Size = size;
	this->m_Speed = speed;
	this->m_font((size.x+size.y/2));
}

Note::~Note()
{

}

void Note::Update()
{
	m_Position += m_Speed;
}

void Note::Draw()
{
	Ellipse(m_Position, m_Size).draw(m_Color);
	m_font(m_Flet).drawCenter(m_Position, Palette::Black);
}

