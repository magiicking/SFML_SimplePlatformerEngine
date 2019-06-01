#pragma once

#include "pch.h"
#include "MagicGridColumn.h"

class MagicGameObject;

using namespace std;
using namespace concurrency;


////////////////////////////////////////////////////////////
/// \brief Заполнить описание.
///
/// 
/// 
/// 
/// \param Параметр     Заполнить параметры.
///
////////////////////////////////////////////////////////////
class MagicGrid
{
private:
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	vector<unique_ptr<MagicGridColumn>> grid;
	float cellSize;
public:
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	MagicGrid(const size_t width, const size_t height, const float _cellSize);

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject* const, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetCellStaticObjectsSet(const size_t x, const size_t y)  const;

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*>* const GetCellDynamicObjectsSet(const size_t x, const size_t y)  const;

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	bool AddStaticObject(MagicGameObject* const object);
};

