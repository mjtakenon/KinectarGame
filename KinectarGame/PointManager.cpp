#pragma once

#include "PointManager.h"

PointManager::PointManager(Vec2 position)
{
	m_Point = 0;

	m_PerfectCount = 0;
	m_GoodCount = 0;
	m_HitCount = 0;
	m_LostCount = 0;

	font(10);

	m_Position = position;
}
PointManager::~PointManager()
{

}

void PointManager::Update()
{

}

void PointManager::Draw() const
{
	//Println(m_PerfectCount, m_GoodCount, m_HitCount, m_LostCount);
	font(Format(L"Perfect:",m_PerfectCount)).drawAt(Vec2(m_Position.x,m_Position.y));
	font(Format(L"Good:",m_GoodCount)).drawAt(Vec2(m_Position.x, m_Position.y + 40));
	font(Format(L"Hit:",m_HitCount)).drawAt(Vec2(m_Position.x, m_Position.y + 80));
	font(Format(L"Lost:",m_LostCount)).drawAt(Vec2(m_Position.x, m_Position.y + 120));
}

void PointManager::addPerfect()
{
	m_PerfectCount++;
	m_Point += m_PerfectPoint;
}

void PointManager::addGood()
{
	m_GoodCount++;
	m_Point += m_GoodPoint;
}

void PointManager::addHit()
{
	m_HitCount++;
	m_Point += m_HitPoint;
}

void PointManager::addLost()
{
	m_LostCount++;
	m_Point += m_LostPoint;
}

