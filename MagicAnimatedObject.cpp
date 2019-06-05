#include "pch.h"
#include "MagicAnimatedObject.h"

void MagicAnimatedObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the texture
	states.texture = GetTexture();

	// you may also override states.shader or states.blendMode if you want

	// draw the vertex array
	target.draw(*GetVertexArray(), states);
}

MagicAnimatedObject::MagicAnimatedObject(const sf::FloatRect _objectRect) : MagicGameObject(_objectRect)
{

}

void MagicAnimatedObject::Tick(float deltaTime)
{
	MagicGameObject::Tick(deltaTime);
}
