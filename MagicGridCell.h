#pragma once

#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"
#include "utilites.h"

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
class MagicGridCell
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
	unique_ptr<concurrent_unordered_set<MagicGameObject*,utilites::PointerHash<MagicGameObject>,utilites::PointerComparator<MagicGameObject>>> static_objects;

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	unique_ptr<concurrent_unordered_set<MagicGameObject*>> dynamic_objects;

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
	MagicGridCell();

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetStaticObjectsSet() const;

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*>* const GetDynamicObjectsSet() const;

	bool AddStaticObject(MagicGameObject* object);
};

