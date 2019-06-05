#pragma once
#include "MagicGameObject.h"
class MagicAnimatedObject :	public MagicGameObject
{
private:

	////////////////////////////////////////////////////////////
	/// \brief Отрисовка.
	/// 
	/// \param target     Куда рисовать.
	/// \param states     Параметры рисования.
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	MagicAnimatedObject(const sf::FloatRect _objectRect);

	void Tick(float deltaTime) override;
};

