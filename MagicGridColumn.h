#pragma once

#include "pch.h"
#include "MagicGridCell.h"

using namespace std;
using namespace concurrency;

class MagicGridColumn
{
public:
	MagicGridColumn(size_t height);
	map<size_t, unique_ptr<MagicGridCell>> cells;
};

