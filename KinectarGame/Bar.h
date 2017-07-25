#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "Object.h"

using namespace std;

class Bar : public Object
{
public:

	Bar(Vec2 position, Vec2 size, Color color);
	~Bar();

	void Update(vector<bool> buttonState);
	void Draw() const;

private:
	Vec2 m_Size;
	Color m_Color;
};