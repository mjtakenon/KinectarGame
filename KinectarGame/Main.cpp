
#include <Siv3D.hpp>

#include "GameManager.h"

void Main()
{
	GameManager* gm = new GameManager();
	gm->Run();

	delete(gm);
}
