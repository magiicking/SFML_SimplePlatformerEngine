#include "pch.h"
#include "MagicGridColumn.h"

MagicGridColumn::MagicGridColumn(const size_t height)
{
	for (size_t i = 0; i < height; i++)
	{
		cells.push_back(make_unique<MagicGridCell>());
	}
}

utilites::MagicGameObjectsConcurrensUnorderedSet* const MagicGridColumn::GetCellStaticObjectsSet(const size_t y) const
{
	return cells[y]->GetStaticObjectsSet();
}

utilites::MagicGameObjectsConcurrensUnorderedSet* const MagicGridColumn::GetCellDynamicObjectsSet(const size_t y) const
{
	return cells[y]->GetDynamicObjectsSet();
}

bool MagicGridColumn::AddStaticObject(const size_t y, MagicGameObject* object)
{
	return cells[y]->AddStaticObject(object);
}

bool MagicGridColumn::AddDynamicObject(const size_t y, MagicGameObject* object)
{
	return cells[y]->AddDynamicObject(object);
}
