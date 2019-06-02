#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"

MagicGridCell::MagicGridCell()
{
	static_objects = make_unique <concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>>();
	dynamic_objects = make_unique <concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>>();
}

concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const MagicGridCell::GetStaticObjectsSet() const
{
	return static_objects.get();
}

concurrent_unordered_set<MagicGameObject*, utilites::PointerHash<MagicGameObject>, utilites::PointerComparator<MagicGameObject>>* const MagicGridCell::GetDynamicObjectsSet() const
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
