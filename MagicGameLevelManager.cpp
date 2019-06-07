#include "pch.h"
#include "MagicGameLevelManager.h"

MagicGameLevelManager::MagicGameLevelManager()
{
	grid = make_unique<MagicGrid>(500, 100, 100.0f);
	dynamicGameObjects.push_back(make_unique<MagicGameObject>(sf::FloatRect(1.0f,1.0f,1.0f,1.0f)));
}
