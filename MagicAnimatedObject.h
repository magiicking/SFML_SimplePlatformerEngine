#pragma once
#include "MagicGameObject.h"
class MagicAnimatedObject :	public MagicGameObject
{
private:

	////////////////////////////////////////////////////////////
	/// \brief ���������.
	/// 
	/// \param target     ���� ��������.
	/// \param states     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
	MagicAnimatedObject(const sf::FloatRect _objectRect);

	void Tick(float deltaTime) override;
};

