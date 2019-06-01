#pragma once

#include "pch.h"
#include "MagicGridCell.h"
#include "utilites.h"

using namespace std;
using namespace concurrency;
using GameObjectsUnorderedSet = concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>;

////////////////////////////////////////////////////////////
/// \brief ��������� ��������.
///
/// 
/// 
/// 
/// \param ��������     ��������� ���������.
///
////////////////////////////////////////////////////////////
class MagicGridColumn
{

private:

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	vector<unique_ptr<MagicGridCell>> cells;

public:
	////////////////////////////////////////////////////////////
	/// \brief ������� ������� ������������ ������.
	///
	/// ������� ������� � ��������� �� ��������.
	/// 
	/// 
	/// \param height     ���������� ����� � �������.
	///
	////////////////////////////////////////////////////////////
	MagicGridColumn(const size_t height);

	////////////////////////////////////////////////////////////
	/// \brief �������� ������ ����������� ��������.
	///
	/// ����������� ������� �������� � ��������� ����,
	/// ����� �� ������������ �� ���������� �� ���������.
	/// 
	/// \param y     y-���������� ������
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetCellStaticObjectsSet(const size_t y) const;

	////////////////////////////////////////////////////////////
	/// \brief �������� ������ ��������� ��������.
	///
	/// ��������� ������� �������� � ��������� ����,
	/// ����� � ������ ����� ��������� ������ �� ������������.
    /// 
    /// \param y     y-���������� ������
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*>* const GetCellDynamicObjectsSet(const size_t y) const;

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	bool AddStaticObject(const size_t y, MagicGameObject* object);
};

