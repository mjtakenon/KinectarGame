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

	// ���L�f�[�^�ɃA�N�Z�X�ł���
	m_data->t;
}

void Title::draw() const
{
	//font(L"Title").drawCenter(Window::Center());
}