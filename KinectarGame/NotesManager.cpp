#include "NotesManager.h"

NotesManager::NotesManager(list<Note> notes)
{
	m_Notes = notes;
}

NotesManager::~NotesManager()
{

}

void NotesManager::Update(pair<vector<int>,vector<int>> input, const Bar bar)
{
	//input����Notes�̒T���A�K�؂ȃm�[�c�̍폜�A�V�����m�[�c�̏o���Ƃ�
	//���y�Ƃ���Ă��璲���Ƃ���?��Game.cpp�̕��ł�点��ׂ�����
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Update();
	}
}

void NotesManager::Draw()
{
	for (auto itr = m_Notes.begin(); itr != m_Notes.end(); itr++)
	{
		itr->Draw();
	}
}
