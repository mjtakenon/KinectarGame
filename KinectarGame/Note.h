#pragma once

#include <Siv3D.hpp>
#include "Object.h"

class Note : public Object
{
public:

	Note(Vec2 position, int string, int flet, Vec2 size, Vec2 speed);
	~Note();

	void Update();
	void Draw();
	
	int getString() { return m_String; };
	int getFlet() { return m_Flet; };

private:
	Vec2 m_Speed;
	Vec2 m_Size;
	Color m_Color;

	int	m_String;
	int m_Flet;

	Font m_font;
};