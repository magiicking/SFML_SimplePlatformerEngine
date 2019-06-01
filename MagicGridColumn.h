#pragma once

#include "pch.h"
#include "MagicGridCell.h"
#include "utilites.h"

using namespace std;
using namespace concurrency;
using GameObjectsUnorderedSet = concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>;

////////////////////////////////////////////////////////////
/// \brief Заполнить описание.
///
/// 
/// 
/// 
/// \param Параметр     Заполнить параметры.
///
////////////////////////////////////////////////////////////
class MagicGridColumn
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
	vector<unique_ptr<MagicGridCell>> cells;

public:
	////////////////////////////////////////////////////////////
	/// \brief Создает колонку определенной высоты.
	///
	/// Создает колонку и заполняет ее ячейками.
	/// 
	/// 
	/// \param height     Количество ячеек в колонке.
	///
	////////////////////////////////////////////////////////////
	MagicGridColumn(const size_t height);

	////////////////////////////////////////////////////////////
	/// \brief Получает список неподвижных объектов.
	///
	/// Неподвижные объекты хранятся в отдельном сете,
	/// чтобы не задумываться об обновлении их положения.
	/// 
	/// \param y     y-координата ячейки
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetCellStaticObjectsSet(const size_t y) const;

	////////////////////////////////////////////////////////////
	/// \brief Получает список подвижных объектов.
	///
	/// Подвижные объекты хранятся в отдельном сете,
	/// чтобы в каждом кадре обновлять ячейку их расположения.
    /// 
    /// \param y     y-координата ячейки
	///
	////////////////////////////////////////////////////////////
	concurrent_unordered_set<MagicGameObject*>* const GetCellDynamicObjectsSet(const size_t y) const;

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	bool AddStaticObject(const size_t y, MagicGameObject* object);
};

