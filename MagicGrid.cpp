#include "pch.h"
#include "MagicGrid.h"
#include "MagicGridColumn.h"

MagicGrid::MagicGrid(const size_t width, const size_t height)
{
	for (size_t i = 0; i < width; i++)
	{
		grid.push_back(make_unique<MagicGridColumn>(height));
	}
}

concurrent_unordered_set<MagicGameObject*>* const MagicGrid::GetCellStaticObjectsSet(size_t x, size_t y) const
{
	return grid[x]->GetCellStaticObjectsSet(y);
}

concurrent_unordered_set<MagicGameObject*>* const MagicGrid::GetCellDynamicObjectsSet(size_t x, size_t y) const
{
	return grid[x]->GetCellDynamicObjectsSet(y);
}
