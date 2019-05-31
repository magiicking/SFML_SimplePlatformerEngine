#include "pch.h"
#include "MagicGridColumn.h"

MagicGridColumn::MagicGridColumn(size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		cells.push_back(make_unique<MagicGridCell>());
	}
}
