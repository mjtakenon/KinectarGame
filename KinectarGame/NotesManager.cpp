#include "NotesManager.h"

NotesManager::NotesManager(list<Note> notes, vector<Bar> bars, int samplingRate)
{
	m_Notes = notes;
	m_Bars = bars;
	m_SamplingRate = samplingRate;

	double prepareTime = 5;
	double visibleTime = prepareTime;
	double hitTime = 1;
	
	m_PrepareFrame = 60 * prepareTime;
	
	m_VisibleSample = m_SamplingRate * visibleTime;
	m_HitSample = m_SamplingRate * hitTime;

	
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->setSize(Vec2(20, 15));
		itr->setSpeed(Vec2(5, 0));

		itr->setPosition(Vec2(m_Bars[itr->getString()].getPosition().x + m_PrepareFrame*itr->getSpeed().x , m_Bars[itr->getString()].getPosition().y));
	}
}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(pair<vector<int>,vector<int>> input, int sample)
{
	//input����Notes�̒T���A�K�؂ȃm�[�c�̍폜�A�V�����m�[�c�̏o���Ƃ�
	for (auto itr = m_Notes.begin(); itr != m_Notes.end();)
	{
		//�o���ƈړ�
		itr->Update(sample, m_SamplingRate, m_Bars[itr->getString()].getPosition(), m_HitSample, m_VisibleSample);

		//list�̗v�f�폜
		if (itr->getPosition().x <= 0 && itr->isVisible())
		{
			itr = m_Notes.erase(itr);
			continue;
		}
		itr++;
	}

	Println(input.first, input.second);
}

void NotesManager::Draw()
{
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Draw();
	}
}
