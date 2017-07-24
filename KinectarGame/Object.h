#pragma once

#include <Siv3D.hpp>

class Object
{
public:
	Object(Vec2 position) { m_Position = position; };
	~Object() {};

	virtual void Update() {};
	virtual void Draw() {};

	Vec2 getPosition() { return m_Position; };

protected:
	Vec2 m_Position;
};