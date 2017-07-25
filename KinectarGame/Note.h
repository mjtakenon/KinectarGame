#pragma once

#include <Siv3D.hpp>

#include "Bar.h"
#include "Object.h"

class Note : public Object
{
public:

	Note(Vec2 position, int string, int flet,int sample, Vec2 size, Vec2 speed);
	~Note();

	void Update(double sample, int samplingRate, Vec2 barPosition, int hitSample, int visibleSample);
	void Draw();
	
	int getString() { return m_String; };
	int getFlet() { return m_Flet; };

	Vec2 getSize() { return m_Size; };
	Vec2 getSpeed() { return m_Speed; };

	void setPosition(Vec2 position) { m_Position = position; };
	void setSize(Vec2 size) { m_Size = size; };
	void setSpeed(Vec2 speed) { m_Speed = speed; };

	bool isEnabled() { return m_isEnable; };
	void setEnable() { m_isEnable = true; };
	void setDisable() { m_isEnable = false; };

	bool isVisible() { return m_isVisible; };
	void setVisible() { m_isVisible = true; };
	void setInvisisble() { m_isVisible = false; };

private:
	Vec2 m_Speed;
	Vec2 m_Size;
	Color m_Color;

	int	m_String;
	int m_Flet;
	int m_Sample;

	Font m_font;

	bool m_isEnable;
	bool m_isVisible;
};
