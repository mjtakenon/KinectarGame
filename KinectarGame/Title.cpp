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
}

void Title::draw() const
{

}