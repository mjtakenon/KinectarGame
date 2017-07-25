#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "Object.h"

using namespace std;

class HitEffect : public Object
{
public:

	HitEffect(Vec2 position, Vec2 size, Color color);
	~HitEffect();

	bool isVisible() { return m_Visible; };

	void Update();
	void Draw() const;

private:
	Vec2 m_Size;
	Color m_Color;

	bool m_Visible;
};