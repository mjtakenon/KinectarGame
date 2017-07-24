#include "GameManager.h"

GameManager::GameManager()
{
	scene = new SceneManager<String, GameData>(SceneManagerOption::ShowSceneName);

	//SceneManagerOption::ShowSceneName ���O���΃V�[�����̃f�o�b�O�\���͏�����
	//MyApp manager;

	// �t�F�[�h�C���E�A�E�g���̐F
	scene->setFadeColor(Palette::Black);

	// �V�[����ݒ�
	scene->add<Title>(L"Title");
	scene->add<Menu>(L"Menu");
	scene->add<Game>(L"Game");

	scene->init(L"Title");

}

GameManager::~GameManager()
{

}

void GameManager::Run()
{
	while (System::Update())
	{
		if (!this->Update())
		{
			break;
		}
	}
}

bool GameManager::Update()
{
	if (!scene->update())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void GameManager::Draw()
{
	scene->draw();
}