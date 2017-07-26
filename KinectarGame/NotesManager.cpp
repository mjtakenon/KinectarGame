#include "NotesManager.h"

NotesManager::NotesManager(Score* score, vector<HitMarker> HitMarkers, int samplingRate)
{
	m_Notes = score->getNotes();
	m_HitMarkers = HitMarkers;
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

		itr->setPosition(Vec2(m_HitMarkers[itr->getString()].getPosition().x + m_VisibleFrame*itr->getSpeed().x , m_HitMarkers[itr->getString()].getPosition().y));
	}

	m_HitEffects = list<HitEffect>();
	m_Bars = list<Bar>();

	for (auto itr = 0; (m_SamplingRate / score->getBPM()) * score->getBlank() + (60 / score->getBPM() * m_SamplingRate) * (itr-10) <= (--m_Notes.end())->getSample(); itr++)
	{
		int sample = (m_SamplingRate / score->getBPM()) * score->getBlank() + (60 / score->getBPM() * m_SamplingRate) * itr;

		Vec2 pos = Vec2(10, m_HitMarkers.begin()->getPosition().y);
		Vec2 size = Vec2(1, m_HitMarkers.begin()->getSize().y * (6 - 1) + (6 - 1) * 5);
		Color color = Palette::Wheat;

		if (itr % 4 == 0)
		{
			size.x = size.x * 2;
			color = Palette::Aquamarine;
		}
		
		m_Bars.push_back(Bar(pos, size, Vec2(5, 0), pos, color, sample));
	}
}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(vector<int> input, vector<vector<bool>> pushed, int sample, PointManager* pm)
{
	//inputからNotesの探索、適切なノーツの削除、新しいノーツの出現とか
	for (auto itr = m_Notes.begin(); itr != m_Notes.end();)
	{
		//出現と移動
		itr->Update(sample, m_SamplingRate, m_HitMarkers[itr->getString()].getPosition(), m_HitSample, m_VisibleSample);

		//listの要素削除
		if (itr->getPosition().x <= 0 && itr->isVisible())
		{
			itr = m_Notes.erase(itr);
			pm->addLost();
			continue;
		}
		itr++;
	}

	//小節線
	for (auto itr = m_Bars.begin(); itr != m_Bars.end(); )
	{
		itr->Update(sample, m_SamplingRate, m_HitMarkers.begin()->getPosition());

		if (!itr->isVisible() && itr->getPosition().x <= 0)
		{
			itr = m_Bars.erase(itr);
			continue;
		}
		itr++;
	}

	for (auto itr = m_HitEffects.begin(); itr != m_HitEffects.end(); )
	{
		itr->Update();
		
		if (!itr->isVisible())
		{
			itr = m_HitEffects.erase(itr);
			continue;
		}
		itr++;
	}

	vector<int> pushedFlet(6,0);

	for (auto n = 0; n < pushed.size(); n++)
	{
		for (auto m = 0; m < pushed[n].size(); m++)
		if (pushed[n][m])
		{
			pushedFlet[m] = n + 1;
		}
	}

	//当たり判定
	for (auto n = 0; n < input.size(); n++)
	{
		if (input[n] == 1)
		{
			for (auto itr = m_Notes.begin(); itr != m_Notes.end();)
			{
				if (itr->getString() != n || itr->getFlet() != pushedFlet[n])
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
				
				if (diffSample <= m_PerfectSample && diffSample >= -m_PerfectSample) //Perfect
				{
					m_HitEffects.push_back(HitEffect(m_HitMarkers[n].getPosition(), Vec2(100, m_HitMarkers[n].getSize().y), Palette::Yellow));
					pm->addPerfect();
				}
				else if (diffSample <= m_GoodSample && diffSample >= -m_GoodSample) //Good
				{
					m_HitEffects.push_back(HitEffect(m_HitMarkers[n].getPosition(), Vec2(100, m_HitMarkers[n].getSize().y), Palette::Green));
					pm->addGood();
				}
				else //Hit
				{
					m_HitEffects.push_back(HitEffect(m_HitMarkers[n].getPosition(), Vec2(100, m_HitMarkers[n].getSize().y), Palette::Blue));
					pm->addHit();
				}
				
				itr = m_Notes.erase(itr);
			}
		}
	}
}

void NotesManager::Draw()
{
	for (auto itr = m_Bars.begin(); itr != m_Bars.end(); itr++)
	{
		itr->Draw();
	}

	for (auto itr = m_HitEffects.begin(); itr != m_HitEffects.end(); itr++)
	{
		itr->Draw();
	}

	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Draw();
	}
}
