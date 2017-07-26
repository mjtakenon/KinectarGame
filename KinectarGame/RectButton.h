#pragma once

#include <Siv3D.hpp>
#include "Object.h"

using namespace std;

class RectButton : public Object
{
public:
	RectButton(Vec2 position, Vec2 size, Color color);

	~RectButton();

	void Update();
	void Draw() const;

	bool isClicked() { return m_Rect.leftPressed; }

private:
	Vec2 m_Size;
	Color m_Color;

	Rect m_Rect;
};
