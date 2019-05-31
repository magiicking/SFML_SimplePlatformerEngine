#pragma once

#include "pch.h"
#include "MagicGridColumn.h"

using namespace std;
using namespace concurrency;



class MagicGrid
{
private:
	map<size_t, unique_ptr<MagicGridColumn>> grid;
public:
	MagicGrid(const size_t width, const size_t height);
};

