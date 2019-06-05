#include "pch.h"
#include "MagicGrid.h"
#include "MagicGridColumn.h"
#include "MagicGameObject.h"

using namespace concurrency;

MagicGrid::MagicGrid(const size_t width, const size_t height, const float _cellSize)
{
	cellSize = _cellSize;
	this->width = width;
	this->height = height;
	for (size_t i = 0; i < width; i++)
	{
		grid.push_back(make_unique<MagicGridColumn>(height));
	}
}

utilites::MagicGameObjectsConcurrensUnorderedSet* const MagicGrid::GetCellStaticObjectsSet(const size_t x, const size_t y) const
{
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return nullptr;
	}
	return grid[x]->GetCellStaticObjectsSet(y);
}

utilites::MagicGameObjectsConcurrensUnorderedSet* const MagicGrid::GetCellDynamicObjectsSet(const size_t x, const size_t y) const
{
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return nullptr;
	}
	return grid[x]->GetCellDynamicObjectsSet(y);
}

bool MagicGrid::AddStaticObject(MagicGameObject* object)
{
	
	const sf::FloatRect objRect = object->GetRect();
	const size_t leftX = (size_t)floorf(objRect.left / cellSize);
	const size_t bottomY = (size_t)floorf(objRect.top / cellSize);
	const size_t rightX = (size_t)floorf((objRect.left + objRect.width) / cellSize);
	const size_t topY = (size_t)floorf((objRect.top + objRect.height) / cellSize);
	bool result = false;
	parallel_for<size_t>(leftX, rightX + 1, 1, [this, object, bottomY, topY, &result](size_t x)
		{
			parallel_for<size_t>(bottomY, topY + 1, 1, [this, x, object, &result](size_t y)
				{
					if (x < 0 || x >= width || y < 0 || y >= height)
					{
						result |= false;
					}
					else
					{
						result |= grid[x]->AddStaticObject(y, object);
					}
				});
		});
	return result;
}

bool MagicGrid::AddDynamicObject(MagicGameObject* object)
{
	const sf::FloatRect objRect = object->GetRect();
	const size_t leftX = (size_t)floorf(objRect.left / cellSize);
	const size_t bottomY = (size_t)floorf(objRect.top / cellSize);
	const size_t rightX = (size_t)floorf((objRect.left + objRect.width) / cellSize);
	const size_t topY = (size_t)floorf((objRect.top + objRect.height) / cellSize);
	bool result = false;
	parallel_for<size_t>(leftX, rightX + 1, 1, [this, object, bottomY, topY, &result](size_t x)
		{
			parallel_for<size_t>(bottomY, topY + 1, 1, [this, x, object, &result](size_t y)
				{
					if (x < 0 || x >= width || y < 0 || y >= height)
					{
						result |= false;
					}
					else
					{
						result |= grid[x]->AddDynamicObject(y, object);
					}
				});
		});
	return result;
}

float MagicGrid::GetCellSize() const
{
	return cellSize;
}

sf::Vector2f MagicGrid::GetOriginPoint() const
{
	return sf::Vector2f(0.0f,0.0f);
}

void MagicGrid::GetCellObjectsSet(const size_t x, const size_t y, ObjectTypeFlags flag, utilites::MagicGameObjectsConcurrensUnorderedSet* objects) const
{
	if (x < 0 || x >= width || y < 0 || y >= height)
	{
		return;
	}
	utilites::MagicGameObjectsConcurrensUnorderedSet* set = grid[x]->GetCellStaticObjectsSet(y);
}
