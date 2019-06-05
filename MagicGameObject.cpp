#include "pch.h"
#include "MagicGameObject.h"

void MagicGameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the texture
	states.texture = m_texture;

	// you may also override states.shader or states.blendMode if you want

	// draw the vertex array
	target.draw(*m_vertices, states);
}

MagicGameObject::MagicGameObject(const sf::FloatRect _objectRect)
{
	objectRect = _objectRect;
	ticking = false;
	m_texture = nullptr;
	m_vertices = make_unique<sf::VertexArray>();
	topLeft = make_unique<sf::Vector2f>(objectRect.left, objectRect.top + objectRect.height);
	topRight = make_unique<sf::Vector2f>(objectRect.left + objectRect.width, objectRect.top + objectRect.height);
	bottomLeft = make_unique<sf::Vector2f>(objectRect.left, objectRect.top);
	bottomRight = make_unique<sf::Vector2f>(objectRect.left + objectRect.width, objectRect.top);
	flags = (uint16_t)ObjectTypeFlags::VisibilityBlocking;
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
	for (size_t i = 0; i < m_vertices->getVertexCount(); i++)
	{
		(*m_vertices)[i].position += difference;
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

sf::Vector2f* MagicGameObject::GetTopLeftPoint() const
{
	return topLeft.get();
}

sf::Vector2f* MagicGameObject::GetTopRightPoint() const
{
	return topRight.get();
}

sf::Vector2f* MagicGameObject::GetBottomLeftPoint() const
{
	return bottomLeft.get();;
}

sf::Vector2f* MagicGameObject::GetBottomRightPoint() const
{
	return bottomRight.get();
}

uint16_t MagicGameObject::GetFlags() const
{
	return flags;
}

sf::VertexArray* MagicGameObject::GetVertexArray() const
{
	return m_vertices.get();
}

sf::Texture* MagicGameObject::GetTexture() const
{
	return m_texture;
}
