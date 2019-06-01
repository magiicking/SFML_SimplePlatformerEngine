#include "pch.h"
#include "MagicGridColumn.h"

MagicGridColumn::MagicGridColumn(size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		cells.push_back(make_unique<MagicGridCell>());
	}
}

concurrent_unordered_set<MagicGameObject*>* const MagicGridColumn::GetCellStaticObjectsSet(size_t y) const
{
	return cells[y]->GetStaticObjectsSet();
}

concurrent_unordered_set<MagicGameObject*>* const MagicGridColumn::GetCellDynamicObjectsSet(size_t y) const
{
	return cells[y]->GetDynamicObjectsSet();
}
