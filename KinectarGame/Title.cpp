#include "Title.h"


void Title::init()
{

}

void Title::update()
{
	if (Input::MouseL.clicked)
	{
		changeScene(L"Menu", 500);
	}

	// 共有データにアクセスできる
	m_data->t;
}

void Title::draw() const
{
	//font(L"Title").drawCenter(Window::Center());
}