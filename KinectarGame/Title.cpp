#include "GameManager.h"


void GameManager::Title::init()
{

}

void GameManager::Title::update()
{
	if (Input::MouseL.clicked)
	{
		// ���̃V�[�P���X�ƁA�t�F�[�h�C���E�A�E�g�̎��ԁi�~���b�j
		changeScene(L"Menu", 500);
	}

	// ���L�f�[�^�ɃA�N�Z�X�ł���
	m_data->t;
}

void GameManager::Title::draw() const
{

}