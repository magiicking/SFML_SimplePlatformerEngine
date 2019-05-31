#include "pch.h"
#include "MagicGrid.h"
#include "MagicGridColumn.h"

MagicGrid::MagicGrid(const size_t width, const size_t height)
{
	for (size_t i = 0; i < width; i++)
	{
		grid.insert(pair<size_t, unique_ptr<MagicGridColumn>>(i, make_unique<MagicGridColumn>(height)));
	}
}
