#include "pch.h"
#include "MagicGameObject.h"

MagicGameObject::MagicGameObject(const sf::FloatRect _objectRect)
{
	objectRect = _objectRect;
}

sf::FloatRect MagicGameObject::GetRect() const
{
	return objectRect;
}
