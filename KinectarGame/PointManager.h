#pragma once

#include <Siv3D.hpp>

class PointManager
{
public:

	PointManager();
	~PointManager();

	void Update();
	void Draw() const;

	void addPerfect();
	void addGood();
	void addHit();
	void addLost();
	
private:

	int m_Point;

	const int m_PerfectPoint = 100;
	const int m_GoodPoint = 50;
	const int m_HitPoint = 20;
	const int m_LostPoint = 0;

	int m_PerfectCount;
	int m_GoodCount;
	int m_HitCount;
	int m_LostCount;

	Font font;
};