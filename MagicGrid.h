#pragma once

#include "pch.h"
#include "MagicGridColumn.h"

class MagicGameObject;

using namespace std;
using namespace concurrency;
using GameObjectsUnorderedSet = concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>;

////////////////////////////////////////////////////////////
/// \brief Класс сетки.
///
/// Предназначен для хранения игровых объектов
/// для дальнейшей проверки столкновений.
/// 
/// 
///
////////////////////////////////////////////////////////////
class MagicGrid
{
private:
	////////////////////////////////////////////////////////////
	/// \brief Сетка.
	///
	/// Содержит вектор уникальных указателей на
	/// объекты-колонки.
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	vector<unique_ptr<MagicGridColumn>> grid;

	////////////////////////////////////////////////////////////
	/// \brief Размер ячейки.
	///
	/// Нужен для перевода мировых координат в номера ячеек.
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	float cellSize;

public:
	////////////////////////////////////////////////////////////
	/// \brief Конструктор объекта.
	///
	/// Создает сетку с определенными шириной, высотой
	/// и размером ячейки
	/// 
	/// \param width     Ширина сетки.
	/// \param height     Высота сетки.
	/// \param _cellSize     Размер ячейки сетки.
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
	concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const GetCellStaticObjectsSet(const size_t x, const size_t y)  const;

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
	bool AddStaticObject(MagicGameObject* object);
};

