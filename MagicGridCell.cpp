#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"

MagicGridCell::MagicGridCell()
{
	objects = make_unique <concurrent_unordered_set<MagicGameObject*>>();
}
