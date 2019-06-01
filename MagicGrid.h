#pragma once

#include "pch.h"
#include "MagicGridColumn.h"

class MagicGameObject;

using namespace std;
using namespace concurrency;


////////////////////////////////////////////////////////////
/// \brief ��������� ��������.
///
/// 
/// 
/// 
/// \param ��������     ��������� ���������.
///
////////////////////////////////////////////////////////////
class MagicGrid
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
	vector<unique_ptr<MagicGridColumn>> grid;
	float cellSize;
public:
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
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
	concurrent_unordered_set<MagicGameObject* const, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetCellStaticObjectsSet(const size_t x, const size_t y)  const;

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
	bool AddStaticObject(MagicGameObject* const object);
};

