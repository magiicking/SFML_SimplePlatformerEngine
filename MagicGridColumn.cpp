#include "pch.h"
#include "MagicGridColumn.h"

MagicGridColumn::MagicGridColumn(size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		cells.insert(pair<size_t, unique_ptr<MagicGridCell>>(i, make_unique<MagicGridCell>()));
	}
}
