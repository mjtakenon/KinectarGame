#pragma once

#include <Siv3D.hpp>
#include <vector>
#include "Object.h"

using namespace std;

class Bar : public Object
{
public:
	Bar(Vec2 position, Vec2 size, Vec2 speed, Vec2 erasePosition, Color color, int hitSample);
	~Bar();

	void Update(double currentSample, int samplingRate, Vec2 hitMarkerPosition);
	void Draw() const;

	bool isVisible() { return m_Visible; };

private:
	Vec2 m_Size;
	Vec2 m_Speed;
	Vec2 m_ErasePosition;
	Color m_Color;

	int m_HitSample;

	bool m_Visible;
};