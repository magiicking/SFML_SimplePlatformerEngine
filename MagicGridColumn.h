#pragma once

#include "pch.h"
#include "MagicGridCell.h"
#include "utilites.h"

using namespace std;
using namespace concurrency;


////////////////////////////////////////////////////////////
/// \brief ������� �����.
///
/// ������ � ���� ������ ����� ������������.
///
////////////////////////////////////////////////////////////
class MagicGridColumn
{


private:

	////////////////////////////////////////////////////////////
	/// \brief ������ ���������� ���������� �� ������.
	///
	////////////////////////////////////////////////////////////
	vector<unique_ptr<MagicGridCell>> cells;

public:
	////////////////////////////////////////////////////////////
	/// \brief ������� ������� ������������ ������.
	///
	/// ������� ������� � ��������� �� ��������.
	///  
	/// \param height     ���������� ����� � �������.
	///
	////////////////////////////////////////////////////////////
	MagicGridColumn(const size_t height);

	////////////////////////////////////////////////////////////
	/// \brief �������� ��� ����������� ��������.
	///
	/// ����������� ������� �������� � ��������� ����,
	/// ����� �� ������������ �� ���������� �� ���������.
	/// 
	/// \param y     y-���������� ������
	///
	////////////////////////////////////////////////////////////
	utilites::MagicGameObjectsConcurrensUnorderedSet* const GetCellStaticObjectsSet(const size_t y) const;

	////////////////////////////////////////////////////////////
	/// \brief �������� ��� ��������� ��������.
	///
	/// ��������� ������� �������� � ��������� ����,
	/// ����� � ������ ����� ��������� ������ �� ������������.
    /// 
    /// \param y     y-���������� ������
	///
	////////////////////////////////////////////////////////////
	utilites::MagicGameObjectsConcurrensUnorderedSet* const GetCellDynamicObjectsSet(const size_t y) const;

	////////////////////////////////////////////////////////////
	/// \brief ��������� � ������ ����������� ������.
	/// 
	/// \param y     y-���������� ������.
	/// \param object     ��������� �� ����������� ������.
	///
	////////////////////////////////////////////////////////////
	bool AddStaticObject(const size_t y, MagicGameObject* object);

	////////////////////////////////////////////////////////////
	/// \brief ��������� � ������ ��������� ������.
	/// 
	/// \param y     y-���������� ������.
	/// \param object     ��������� �� ����������� ������.
	///
	////////////////////////////////////////////////////////////
	bool AddDynamicObject(const size_t y, MagicGameObject* object);
};

