#include "Title.h"


void Title::init()
{

}

void Title::update()
{
	if (Input::MouseL.clicked)
	{
		// 次のシーケンスと、フェードイン・アウトの時間（ミリ秒）
		changeScene(L"Menu", 500);
	}

	// 共有データにアクセスできる
	m_data->t;
}

void Title::draw() const
{

}