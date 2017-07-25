#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "Object.h"

using namespace std;

class GuitarString : public Object
{
public:

	GuitarString(Vec2 position, Vec2 size, Color color);
	~GuitarString();

	void Update(int soundTime);
	void Draw() const;

private:
	Vec2 m_Size;
	Color m_Color;
};
