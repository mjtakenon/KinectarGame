#include "Game.h"


void Game::init()
{
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
}