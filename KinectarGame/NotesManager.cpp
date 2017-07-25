#include "NotesManager.h"

NotesManager::NotesManager(list<Note> notes, vector<Bar> bars, int samplingRate)
{
	m_Notes = notes;
	m_Bars = bars;
	m_SamplingRate = samplingRate;

	double visibleTime = 5;
	
	double hitTime = 0.5;
	double goodTime = 0.3;
	double perfectTime = 0.1;
	
	m_VisibleFrame = 60 * visibleTime;
	
	m_VisibleSample = m_SamplingRate * visibleTime;

	m_HitSample = m_SamplingRate * hitTime;
	m_GoodSample = m_SamplingRate * goodTime;
	m_PerfectSample = m_SamplingRate * perfectTime;

	
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->setSize(Vec2(20, 15));
		itr->setSpeed(Vec2(5, 0));

		itr->setPosition(Vec2(m_Bars[itr->getString()].getPosition().x + m_VisibleFrame*itr->getSpeed().x , m_Bars[itr->getString()].getPosition().y));
	}
}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(vector<int> input, int sample)
{
	//inputからNotesの探索、適切なノーツの削除、新しいノーツの出現とか
	for (auto itr = m_Notes.begin(); itr != m_Notes.end();)
	{
		//出現と移動
		itr->Update(sample, m_SamplingRate, m_Bars[itr->getString()].getPosition(), m_HitSample, m_VisibleSample);

		//listの要素削除
		if (itr->getPosition().x <= 0 && itr->isVisible())
		{
			itr = m_Notes.erase(itr);
			continue;
		}
		itr++;
	}

	//当たり判定
	for (auto n = 0; n < input.size(); n++)
	{
		if (input[n] == 1)
		{
			for (auto itr = m_Notes.begin(); itr != m_Notes.end();)
			{
				if (itr->getString() != n)
				{
					itr++;
					continue;
				}

				int diffSample = itr->getSample() - sample;

				if (diffSample > m_HitSample)
				{
					itr++;
					continue;
				}
				
				if (diffSample <= m_PerfectSample) //Perfect
				{
					
				}
				else if (diffSample <= m_GoodSample) //Good
				{

				}
				else //Hit
				{

				}
				
				itr = m_Notes.erase(itr);


			}
		}
	}

	Println(input);
}

void NotesManager::Draw()
{
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Draw();
	}
}
