#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"

MagicGridCell::MagicGridCell()
{
	static_objects = make_unique <utilites::MagicGameObjectsConcurrensUnorderedSet>();
	dynamic_objects = make_unique <utilites::MagicGameObjectsConcurrensUnorderedSet>();
}

utilites::MagicGameObjectsConcurrensUnorderedSet* const MagicGridCell::GetStaticObjectsSet() const
{
	return static_objects.get();
}

utilites::MagicGameObjectsConcurrensUnorderedSet* const MagicGridCell::GetDynamicObjectsSet() const
{
	return dynamic_objects.get();
}

bool MagicGridCell::AddStaticObject(MagicGameObject* object)
{
	return static_objects->insert(object).second;
}

bool MagicGridCell::AddDynamicObject(MagicGameObject* object)
{
	return dynamic_objects->insert(object).second;
}

bool MagicGridCell::HasStaticObjects() const
{
	return !static_objects->empty();
}

bool MagicGridCell::HasDynamicObjects() const
{
	return !dynamic_objects->empty();
}
