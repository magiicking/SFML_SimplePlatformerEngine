#pragma once

#include "pch.h"
#include "MagicGridColumn.h"

class MagicGameObject;

using namespace std;
using namespace concurrency;
using GameObjectsUnorderedSet = concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>;

////////////////////////////////////////////////////////////
/// \brief ����� �����.
///
/// ������������ ��� �������� ������� ��������
/// ��� ���������� �������� ������������.
/// 
/// 
///
////////////////////////////////////////////////////////////
class MagicGrid
{
private:
	////////////////////////////////////////////////////////////
	/// \brief �����.
	///
	/// �������� ������ ���������� ���������� ��
	/// �������-�������.
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	vector<unique_ptr<MagicGridColumn>> grid;

	////////////////////////////////////////////////////////////
	/// \brief ������ ������.
	///
	/// ����� ��� �������� ������� ��������� � ������ �����.
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	float cellSize;

public:
	////////////////////////////////////////////////////////////
	/// \brief ����������� �������.
	///
	/// ������� ����� � ������������� �������, �������
	/// � �������� ������
	/// 
	/// \param width     ������ �����.
	/// \param height     ������ �����.
	/// \param _cellSize     ������ ������ �����.
	///
	////////////////////////////////////////////////////////////
	MagicGrid(const size_t width, const size_t height, const float _cellSize);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetCellStaticObjectsSet(const size_t x, const size_t y)  const;

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*>* const GetCellDynamicObjectsSet(const size_t x, const size_t y)  const;

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	bool AddStaticObject(MagicGameObject* object);
};

