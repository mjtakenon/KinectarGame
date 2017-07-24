#include "Menu.h"


void Menu::init()
{

}

void Menu::update()
{
	if (Input::MouseL.clicked)
	{
		changeScene(L"Game", 500);
	}
}

void Menu::draw() const
{
	//font(L"Menu").drawCenter(Window::Center());

}