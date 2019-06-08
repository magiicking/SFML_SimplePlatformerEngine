#include "pch.h"
#include "MagicGameLevelManager.h"

MagicGameLevelManager::MagicGameLevelManager()
{
	grid = make_unique<MagicGrid>(500, 100, 100.0f);
	dynamicGameObjects.push_back(make_unique<MagicGameObject>(sf::FloatRect(10.0f,10.0f,50.0f,50.0f)));
	grid->AddDynamicObject(dynamicGameObjects[0].get());
	/*staticGameObjects.push_back(make_unique<MagicGameObject>(sf::FloatRect(100.0f, 10.0f, 30.0f, 30.0f)));
	grid->AddStaticObject(staticGameObjects[0].get());*/
	/*staticGameObjects.push_back(make_unique<MagicGameObject>(sf::FloatRect(10.0f, 100.0f, 30.0f, 30.0f)));
	grid->AddStaticObject(staticGameObjects[1].get());
	staticGameObjects.push_back(make_unique<MagicGameObject>(sf::FloatRect(100.0f, 100.0f, 30.0f, 30.0f)));
	grid->AddStaticObject(staticGameObjects[2].get());*/
	dynamicGameObjects[0]->SetFlag(ObjectTypeFlags::Lighting);
	dynamicGameObjects[0]->AddLightPoint(sf::Vector2f(0.5, 0.5));

	lamp = sf::Vector2f(80.0, 90.0);
}

void MagicGameLevelManager::DrawGameObjects(sf::RenderTarget* target, sf::FloatRect viewRect) const
{
	unique_ptr<utilites::MagicGameObjectsConcurrensUnorderedSet> set = make_unique<utilites::MagicGameObjectsConcurrensUnorderedSet>();
	utilites::GetObjectsInRect(&viewRect, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
	std::for_each(set->begin(), set->end(), [&target](MagicGameObject* obj)
		{
			target->draw(*obj);
		});
}

void MagicGameLevelManager::DrawLighting(sf::RenderTarget* target, sf::FloatRect viewRect) const
{
	concurrent_vector<utilites::LightingCollisionPoint> points;
	utilites::GetPointsForLightingPoligon(&viewRect, &lamp, grid.get(), &points);
	sf::VertexArray vertices;
	vertices.setPrimitiveType(sf::Triangles);
	for (size_t i = 0; i < points.size() - 1; i++)
	{
		vertices.append(sf::Vertex(lamp,sf::Color::Red));
		vertices.append(sf::Vertex(points[i].point, sf::Color::Red));
		vertices.append(sf::Vertex(points[i + 1].point, sf::Color::Red));
	}
	vertices.append(sf::Vertex(lamp, sf::Color::Red));
	vertices.append(sf::Vertex(points[points.size() - 1].point, sf::Color::Red));
	vertices.append(sf::Vertex(points[0].point, sf::Color::Red));
	target->draw(vertices);
}
