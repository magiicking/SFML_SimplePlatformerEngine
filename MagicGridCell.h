#pragma once

#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"
#include "utilites.h"

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
class MagicGridCell
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
	unique_ptr<concurrent_unordered_set<MagicGameObject*,utilites::PointerHash<MagicGameObject>,utilites::PointerComparator<MagicGameObject>>> static_objects;

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	unique_ptr<concurrent_unordered_set<MagicGameObject*>> dynamic_objects;

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
	MagicGridCell();

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetStaticObjectsSet() const;

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*>* const GetDynamicObjectsSet() const;

	bool AddStaticObject(MagicGameObject* object);
};

