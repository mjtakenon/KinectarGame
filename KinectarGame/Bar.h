#pragma once

#include <Siv3D.hpp>
#include "Object.h"

class Bar : public Object
{
public:

	Bar(Vec2 position, Vec2 size, Color color);
	~Bar();

	void Update();
	void Draw();

private:
	Vec2 m_Size;
	Color m_Color;
};