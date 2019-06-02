#pragma once

#include "pch.h"

////////////////////////////////////////////////////////////
/// \brief ������� ������.
///
/// ����� ������� ������� �������.
/// ���� ����� ���������� � ���� ����������� ��������,
/// �� ��� ������ � ��� ������.
/// 
/// \param ��������     ��������� ���������.
///
////////////////////////////////////////////////////////////
class MagicGameObject : public sf::Drawable
{
private:
	////////////////////////////////////////////////////////////
	/// \brief ������������� �������.
	///
	/// ����� ������� ���� - ��������� � ������������.
	/// ������ � ������ - �������.
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect objectRect;

	////////////////////////////////////////////////////////////
	/// \brief ������ ������ ��� ���������.
	///
	/// 
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	sf::VertexArray m_vertices;

	////////////////////////////////////////////////////////////
	/// \brief ��������� �� ��������.
	///
	/// 
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	sf::Texture* m_texture;

	////////////////////////////////////////////////////////////
	/// \brief ���������.
	///
	/// 
	/// 
	/// 
	/// \param target     ���� ��������.
	/// \param states     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

public:

	////////////////////////////////////////////////////////////
	/// \brief �������.
	///
	/// ����������, ����� �� �������������� ���������� ������� Tick
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	bool ticking;

	////////////////////////////////////////////////////////////
	/// \brief ����������� �������.
	///
	/// ���� ��������� ������ �������������.
	/// 
	/// 
	/// \param _objectRect     ������������� ������� (��������� � ������).
	///
	////////////////////////////////////////////////////////////
	MagicGameObject(const sf::FloatRect _objectRect);

	////////////////////////////////////////////////////////////
	/// \brief �������� ������������� �������.
	///
	/// 
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	sf::FloatRect GetRect() const;

	////////////////////////////////////////////////////////////
	/// \brief ���������� ��������� �������.
	///
	/// ��������������� ��������� �������� ������ ���� ��������������,
	/// � ����� ��������� �������.
	/// 
	/// \param newPosition     ����� ���������.
	///
	////////////////////////////////////////////////////////////
	void SetPosition(sf::Vector2f newPosition);

	////////////////////////////////////////////////////////////
	/// \brief �������.
	///
	/// �������, �������������� "���������������" ������� �� ��������:
	/// ��������, ������� � �.�.
	/// 
	/// \param deltaTime     ���������� ���������� �������.
	///
	////////////////////////////////////////////////////////////
	void Tick(float deltaTime);
};

