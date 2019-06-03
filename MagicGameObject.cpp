#include "pch.h"
#include "MagicGameObject.h"

void MagicGameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the texture
	states.texture = m_texture;

	// you may also override states.shader or states.blendMode if you want

	// draw the vertex array
	target.draw(m_vertices, states);
}

MagicGameObject::MagicGameObject(const sf::FloatRect _objectRect)
{
	objectRect = _objectRect;
	ticking = false;
	m_texture = nullptr;
	topLeft = make_unique<sf::Vector2f>(objectRect.left, objectRect.top + objectRect.height);
}

sf::FloatRect MagicGameObject::GetRect() const
{
	return objectRect;
}

void MagicGameObject::SetPosition(sf::Vector2f newPosition)
{
	sf::Vector2f difference = newPosition - sf::Vector2f(objectRect.left, objectRect.top);
	objectRect.left += difference.x;
	objectRect.top += difference.y;
	for (size_t i = 0; i < m_vertices.getVertexCount(); i++)
	{
		m_vertices[i].position += difference;
	}
	topLeft->x += difference.x;
	topLeft->y += difference.y;
	topRight->x += difference.x;
	topRight->y += difference.y;
	bottomLeft->x += difference.x;
	bottomLeft->y += difference.y;
	bottomRight->x += difference.x;
	bottomRight->y += difference.y;
}

void MagicGameObject::Tick(float deltaTime)
{
	if (ticking)
	{

	}
}

void MagicGameObject::GetCornersPointers(vector<sf::Vector2f*>* const ret_vector)
{
	ret_vector->push_back(topLeft.get());
	ret_vector->push_back(topRight.get());
	ret_vector->push_back(bottomLeft.get());
	ret_vector->push_back(bottomRight.get());
}
