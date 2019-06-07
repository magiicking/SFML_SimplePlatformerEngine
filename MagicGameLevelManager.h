#pragma once

#include "pch.h"
#include "MagicGrid.h"

class MagicGameLevelManager
{
private:
	unique_ptr<MagicGrid> grid;
	vector<sf::Vector2f> lightingSources;
	vector<unique_ptr<MagicGameObject>> dynamicGameObjects;

public:
	MagicGameLevelManager();

	void DrawGameObjects(sf::RenderTarget* target, sf::FloatRect viewRect) const;
	void DrawLighting(sf::RenderTarget* target, sf::FloatRect viewRect) const;

};

