#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"

MagicGridCell::MagicGridCell()
{
	static_objects = make_unique <concurrent_unordered_set<MagicGameObject* const, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>>();
	dynamic_objects = make_unique <concurrent_unordered_set<MagicGameObject*>>();
}

concurrent_unordered_set<MagicGameObject* const, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const MagicGridCell::GetStaticObjectsSet() const
{
	return static_objects.get();
}

concurrent_unordered_set<MagicGameObject*>* const MagicGridCell::GetDynamicObjectsSet() const
{
	return dynamic_objects.get();
}

bool MagicGridCell::AddStaticObject(MagicGameObject* const object)
{
	return static_objects->insert(object).second;
}
