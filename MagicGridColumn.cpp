#include "pch.h"
#include "MagicGridColumn.h"

MagicGridColumn::MagicGridColumn(const size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		cells.push_back(make_unique<MagicGridCell>());
	}
}

concurrent_unordered_set<MagicGameObject* const, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const MagicGridColumn::GetCellStaticObjectsSet(const size_t y) const
{
	return cells[y]->GetStaticObjectsSet();
}

concurrent_unordered_set<MagicGameObject*>* const MagicGridColumn::GetCellDynamicObjectsSet(const size_t y) const
{
	return cells[y]->GetDynamicObjectsSet();
}

bool MagicGridColumn::AddStaticObject(const size_t y, MagicGameObject* const object)
{
	return cells[y]->AddStaticObject(object);
}
