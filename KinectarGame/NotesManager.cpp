#include "NotesManager.h"

NotesManager::NotesManager(list<Note> notes, Bar bar, int samplingRate)
{
	m_Notes = notes;
	m_SamplingRate = samplingRate;

	double prepareTime = 5;
	double visibleTime = prepareTime;
	double hitTime = 1;
	
	m_PrepareFrame = 60 * prepareTime;
	
	m_VisibleSample = m_SamplingRate * visibleTime;
	m_HitSample = m_SamplingRate * hitTime;

	
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->setSize(Vec2(10, 10));
		itr->setSpeed(Vec2(10, 0));
		itr->setPosition(Vec2(bar.getPosition().x + m_PrepareFrame*itr->getSpeed().x , itr->getString() * 20 + 100));
	}


}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(pair<vector<int>,vector<int>> input, int sample, Bar bar)
{
	//input����Notes�̒T���A�K�؂ȃm�[�c�̍폜�A�V�����m�[�c�̏o���Ƃ� 
	//���y�Ƃ���Ă��璲���Ƃ���?��Game.cpp�̕��ł�点��ׂ����� ������?
	for (auto itr = m_Notes.begin(); itr != m_Notes.end();)
	{
		//�o���ƈړ�
		itr->Update(sample, m_SamplingRate, bar.getPosition(), m_HitSample, m_VisibleSample);

		//list�̗v�f�폜�A�ʓ|�ł���
		if (itr->getPosition().x <= 0 && itr->isVisible())
		{
			itr = m_Notes.erase(itr);
			continue;
		}
		itr++;
	}


}

void NotesManager::Draw()
{
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Draw();
		Println(itr->getPosition());
	}
}
