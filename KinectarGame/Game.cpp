#include "Game.h"


void Game::init()
{
	font(50);
}

void Game::update()
{
	if (Input::MouseL.clicked)
	{
		changeScene(L"Menu", 500);
	}
}

void Game::draw() const
{
	//font(L"Game").drawCenter(Window::Center());
}