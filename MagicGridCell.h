#pragma once

#include "pch.h"
#include "MagicGridCell.h"
#include "MagicGameObject.h"

using namespace std;
using namespace concurrency;

class MagicGridCell
{
private:
	unique_ptr<concurrent_unordered_set<MagicGameObject*>> objects;
public:
	MagicGridCell();
};

