#include "GameManager.h"


void GameManager::Title::init()
{

}

void GameManager::Title::update()
{
	if (Input::MouseL.clicked)
	{
		// 次のシーケンスと、フェードイン・アウトの時間（ミリ秒）
		changeScene(L"Menu", 500);
	}

	// 共有データにアクセスできる
	m_data->t;
}

void GameManager::Title::draw() const
{

}