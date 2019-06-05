#include "pch.h"
#include "utilites.h"
#include "MagicGrid.h"
#include "MagicGameObject.h"

float utilites::Dot2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2)
{
	return vector1->x * vector2->x + vector1->y * vector2->y;
}

float utilites::Cross2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2)
{
	return vector1->x * vector2->y - vector1->y * vector2->x;
}

float utilites::CrossAB_AC(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C)
{
	//sf::Vector2f AB = *B - *A;
	//sf::Vector2f AC = *C - *A;
	return (B->x - A->x) * (C->y - A->y) - (B->y - A->y) * (C->x - A->x);
}

bool utilites::GetLineByPoints(const sf::Vector2f* const A, const sf::Vector2f* const B, sf::Vector3f* const result)
{
	*result = sf::Vector3f(A->y - B->y, B->x - A->x, A->x * B->y - B->x * A->y);
	if (NearZero(result->x) && NearZero(result->y))
	{
		return false;
	}
	return true;
}

bool utilites::GetLinesIntersection(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result)
{
	float a1 = line1->x;
	float b1 = line1->y;
	float c1 = line1->z;
	float a2 = line2->x;
	float b2 = line2->y;
	float c2 = line2->z;
	//Решение формулой Крамера. Не понимаю, но использую.
	if (isfinite(a1) && isfinite(a2))
	{
		float divider = a1 * b2 - a2 * b1;
		if (NearZero(divider))
		{
			//Я ненавижу параллельные прямые.
			//Две прямых с разными знаками коэффициентов могут оказаться одной прямой.
			//А еще две прямые с совершенно разными коэффициентами, но пропорциональными a и b тоже могут оказаться одной прямой.
			//Попробую какое-нибудь извращение.
			if (a1 * a2 < 0 || b1 * b2 < 0)
			{
				a1 *= -1;
				b1 *= -1;
				c1 *= -1;
			}
			float normalizer;
			if (!NearZero(a1))
			{
				normalizer = a2 / a1;
				a2 /= normalizer;
				b2 /= normalizer;
				c2 /= normalizer;
			}
			else if (!NearZero(b1))
			{
				normalizer = b2 / b1;
				a2 /= normalizer;
				b2 /= normalizer;
				c2 /= normalizer;
			}
			if (NearZero(a1 - a2) && NearZero(b1 - b2) && NearZero(c1 - c2))
			{
				//same line
				result->x = std::numeric_limits<float>::infinity();
				result->y = std::numeric_limits<float>::infinity();
				return true;
				
			}
			else
			{
				//parallel lines
				result->x = std::numeric_limits<float>::quiet_NaN();
				result->y = std::numeric_limits<float>::quiet_NaN();
				return false;
			}

		}
		else
		{
			result->x = -1 * (c1 * b2 - c2 * b1) / divider;
			result->y = -1 * (a1 * c2 - a2 * c1) / divider;
			return true;
		}
	}
	else
	{
		result->x = std::numeric_limits<float>::quiet_NaN();
		result->y = std::numeric_limits<float>::quiet_NaN();
		return false;
	}
	return false;
}

bool utilites::GetLinesIntersection(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const result)
{
	float delimeter = (B->x - A->x) * (D->y - C->y) - (D->x - C->x) * (B->y - A->y);
	if (!NearZero(delimeter))
	{
		float thing1 = (B->x * A->y - A->x * B->y);
		float thing2 = (D->x * C->y - C->x * D->y);
		result->x = (thing1 * (D->x - C->x) - thing2 * (B->x - A->x)) / delimeter;
		result->y = (thing1 * (D->y - C->y) - thing2 * (B->y - A->y)) / delimeter;
		return true;
	}
	return false;
}

bool utilites::NearZero(float value)
{
	return fabsf(value) <= numeric_limits<float>::epsilon();
}

bool utilites::IsPointOnSegment(const sf::Vector2f* const segmentStart, const sf::Vector2f* const segmentEnd, const sf::Vector2f* const point)
{
	//Проверка, если точка по осям х и у находится в пределах отрезка, и что отрезок и точка на одной прямой
	return ((segmentStart->x <= point->x && point->x <= segmentEnd->x) || (segmentEnd->x <= point->x && point->x <= segmentStart->x))
		&& ((segmentStart->y <= point->y && point->y <= segmentEnd->y) || (segmentEnd->y <= point->y && point->y <= segmentStart->y))
		&& NearZero(CrossAB_AC(segmentStart, segmentEnd, point));
	
}

float utilites::VectorLenght(const sf::Vector2f* const vect)
{
	return sqrtf(vect->x * vect->x + vect->y * vect->y);
}

void utilites::GetTriangleCenter(const sf::Vector2f* const a1, const sf::Vector2f* const a2, const sf::Vector2f* const a3, sf::Vector2f* const result)
{
	*result = sf::Vector2f((a1->x + a2->x + a3->x) / 3.0f, (a1->y + a2->y + a3->y) / 3.0f);
}

void utilites::GetNormal(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const TriangleCenter, sf::Vector2f* const result)
{
	unique_ptr<sf::Vector2f> AB = make_unique<sf::Vector2f>(*B - *A);
	unique_ptr<sf::Vector2f> AC = make_unique<sf::Vector2f>(*TriangleCenter - *A);
	*result = sf::Vector2f(-AB->y, AB->x);
	*result /= VectorLenght(result);
	if (Dot2d(AC.get(), result) > 0)
	{
		*result *= -1.0f;
	}

}

bool utilites::GetSegmentsIntersection(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const out)
{
	const sf::Vector2f* A_temp = A;
	const sf::Vector2f* B_temp = B;
	const sf::Vector2f* C_temp = C;
	const sf::Vector2f* D_temp = D;
	const sf::Vector2f* temp_temp = D;
	//Добавить проверку. Вдруг отрезки вообще совпадают.
	if (A_temp->x > B_temp->x)
	{
		temp_temp = B_temp;
		B_temp = A_temp;
		A_temp = temp_temp;
	}
	if (C_temp->x > D_temp->x)
	{
		temp_temp = D_temp;
		D_temp = C_temp;
		C_temp = temp_temp;
	}
	
	if (GetLinesIntersection(A_temp, B_temp, C_temp, D_temp, out))
	{
		return IsPointOnSegment(A_temp, B_temp, out) && IsPointOnSegment(C_temp, D_temp, out);
	}
	else
	{
		if (IsPointOnSegment(A_temp, B_temp, C_temp))
		{
			if (IsPointOnSegment(C_temp, D_temp, A_temp))
			{
				*out = (*A_temp + *C_temp) / 2.0f;
			}
			else
			{
				*out = (*B_temp + *C_temp) / 2.0f;
			}
			return true;
		}
		else if (IsPointOnSegment(A_temp, B_temp, D_temp))
		{
			if (IsPointOnSegment(C_temp, D_temp, A_temp))
			{
				*out = (*A_temp + *D_temp) / 2.0f;
			}
			else
			{
				*out = (*B_temp + *D_temp) / 2.0f;
			}
			return true;
		}
		else if (IsPointOnSegment(C_temp, D_temp, A_temp))
		{
			if (IsPointOnSegment(A_temp, B_temp, C_temp))
			{
				*out = (*C_temp + *A_temp) / 2.0f;
			}
			else
			{
				*out = (*D_temp + *A_temp) / 2.0f;
			}
			return true;
		}
		else if (IsPointOnSegment(C_temp, D_temp, B_temp))
		{
			if (IsPointOnSegment(A_temp, B_temp, C_temp))
			{
				*out = (*C_temp + *B_temp) / 2.0f;
			}
			else
			{
				*out = (*D_temp + *B_temp) / 2.0f;
			}
			return true;
		}
	}
	

	return false;
}

bool utilites::GetRayAndViewBorderIntersectionPoint(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::FloatRect* const viewRect, sf::Vector2f* const result)
{
	if (NearZero(A->x - B->x) && NearZero(A->y - B->y))
	{
		return false;
	}
	if ((A->x < viewRect->left || A->x > viewRect->left + viewRect->width
		|| A->y < viewRect->top || A->y > viewRect->top + viewRect->height)
		&& (B->x < viewRect->left || B->x > viewRect->left + viewRect->width
			|| B->y < viewRect->top || B->y > viewRect->top + viewRect->height))
	{
		return false;
	}
	sf::Vector2f direction = *B - *A;
	direction /= VectorLenght(&direction);
	
	float borderX = 0.0f;
	float borderY = 0.0f;
	float borderDirectionX = 0.0f;
	float borderDirectionY = 0.0f;
	
	if (NearZero(direction.x))
	{
		if (direction.y > 0)
		{
			borderY = viewRect->top + viewRect->height;
		}
		else
		{
			borderY = viewRect->top;
		}
		result->y = borderY;
		result->x = A->x;
		return true;
	}
	else if (NearZero(direction.y))
	{
		if (direction.x > 0)
		{
			borderX = viewRect->left + viewRect->width;
		}
		else
		{
			borderX = viewRect->left;
		}
		result->y = A->y;
		result->x = borderX;
		return true;
	}
	else
	{
		if (direction.x > 0)
		{
			borderX = viewRect->left + viewRect->width;
		}
		else
		{
			borderX = viewRect->left;
		}
		borderDirectionX = borderX - A->x;
		if (direction.y > 0)
		{
			borderY = viewRect->top + viewRect->height;
		}
		else
		{
			borderY = viewRect->top;
		}
		borderDirectionY = borderY - A->y;

		result->x = borderX;
		result->y = borderDirectionX / direction.x * direction.y + A->y;
		if (result->y < viewRect->top || result->y > viewRect->top + viewRect->height)
		{
			result->y = borderY;
			result->x = borderDirectionY / direction.y * direction.x + A->x;
		}

		return true;
	}
	return false;
}

bool utilites::GetRayAndRectCollisionPoint(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::FloatRect* const rect, sf::Vector2f* const result, bool * const blocking)
{
	uint8_t code_a = GetPointCodeCohenSutherland(A,rect);
	uint8_t code_b = GetPointCodeCohenSutherland(B, rect);
	sf::Vector2f rectBottomLeftPoint = sf::Vector2f(rect->left, rect->top);
	sf::Vector2f rectBottomRightPoint = sf::Vector2f(rect->left + rect->width, rect->top);
	sf::Vector2f rectTopLeftPoint = sf::Vector2f(rect->left, rect->top + rect->height);
	sf::Vector2f rectTopRightPoint = sf::Vector2f(rect->left + rect->width, rect->top + rect->height);
	bool booleResult = false;
	//Начало луча снаружи. Пока еще неизвестно, есть ли пересечение
	if (code_a)
	{
		//Обе точки с одной стороны от прямоугольника, пересечения точно нет.
		if (code_a & code_b)
		{
			return booleResult;
		}
		//Точки с разных сторон прямоугольника. Есть смысл заняться проверкой.
		switch (code_a)
		{
			//Источник луча слева от прямоугольника. Достаточно проверить левую грань.
			case (uint8_t)CohenSutherlandCode::Left:
				{
					booleResult = GetSegmentsIntersection(A, B, &rectBottomLeftPoint, &rectTopLeftPoint, result);
					*blocking = !VectorsAreEqual(&rectBottomLeftPoint, result) && !VectorsAreEqual(&rectTopLeftPoint, result);
					break;
				}
			//Источник луча справа от прямоугольника. Достаточно проверить правую грань.
			case (uint8_t)CohenSutherlandCode::Right:
				{
					booleResult = GetSegmentsIntersection(A, B, &rectBottomRightPoint, &rectTopRightPoint, result);
					*blocking = !VectorsAreEqual(&rectBottomRightPoint, result) && !VectorsAreEqual(&rectTopRightPoint, result);
					break;
				}
			//Источник луча снизу от прямоугольника. Достаточно проверить нижнюю грань.
			case (uint8_t)CohenSutherlandCode::Bottom:
				{
					booleResult = GetSegmentsIntersection(A, B, &rectBottomLeftPoint, &rectBottomRightPoint, result);
					*blocking = !VectorsAreEqual(&rectBottomLeftPoint, result) && !VectorsAreEqual(&rectBottomRightPoint, result);
					break;
				}
			//Источник луча сверху от прямоугольника. Достаточно проверить верхнюю грань.
			case (uint8_t)CohenSutherlandCode::Top:
				{
					booleResult = GetSegmentsIntersection(A, B, &rectTopRightPoint, &rectTopLeftPoint, result);
					*blocking = !VectorsAreEqual(&rectTopRightPoint, result) && !VectorsAreEqual(&rectTopLeftPoint, result);
					break;
				}
			//Источник луча слева-снизу от прямоугольника. Достаточно проверить левую и нижнюю грани.
			case (uint8_t)CohenSutherlandCode::Left | (uint8_t)CohenSutherlandCode::Bottom:
				{
					if (GetSegmentsIntersection(A, B, &rectBottomLeftPoint, &rectTopLeftPoint, result))
					{
						booleResult = true;
						*blocking = !VectorsAreEqual(&rectBottomLeftPoint, result) && !VectorsAreEqual(&rectTopLeftPoint, result);
					}
					else
					{
						booleResult = GetSegmentsIntersection(A, B, &rectBottomLeftPoint, &rectBottomRightPoint, result);
						*blocking = !VectorsAreEqual(&rectBottomLeftPoint, result) && !VectorsAreEqual(&rectBottomRightPoint, result);
					}
					break;
				}
			//Источник луча слева-сверху от прямоугольника. Достаточно проверить левую и верхнюю грани.
			case (uint8_t)CohenSutherlandCode::Left | (uint8_t)CohenSutherlandCode::Top:
				{
					if (GetSegmentsIntersection(A, B, &rectBottomLeftPoint, &rectTopLeftPoint, result))
					{
						booleResult = true;
						*blocking = !VectorsAreEqual(&rectBottomLeftPoint, result) && !VectorsAreEqual(&rectTopLeftPoint, result);
					}
					else
					{
						booleResult = GetSegmentsIntersection(A, B, &rectTopRightPoint, &rectTopLeftPoint, result);
						*blocking = !VectorsAreEqual(&rectTopRightPoint, result) && !VectorsAreEqual(&rectTopLeftPoint, result);
					}
					break;
				}
			//Источник луча справа-снизу от прямоугольника. Достаточно проверить правую и нижнюю грани.
			case (uint8_t)CohenSutherlandCode::Right | (uint8_t)CohenSutherlandCode::Bottom:
				{
					if (GetSegmentsIntersection(A, B, &rectBottomRightPoint, &rectTopRightPoint, result))
					{
						booleResult = true;
						*blocking = !VectorsAreEqual(&rectBottomRightPoint, result) && !VectorsAreEqual(&rectTopRightPoint, result);
					}
					else
					{
						booleResult = GetSegmentsIntersection(A, B, &rectBottomLeftPoint, &rectBottomRightPoint, result);
						*blocking = !VectorsAreEqual(&rectBottomLeftPoint, result) && !VectorsAreEqual(&rectBottomRightPoint, result);
					}
					break;
				}
			//Источник луча справа-сверху от прямоугольника. Достаточно проверить правую и верхнюю грани.
			case (uint8_t)CohenSutherlandCode::Right | (uint8_t)CohenSutherlandCode::Top:
				{
					if (GetSegmentsIntersection(A, B, &rectBottomRightPoint, &rectTopRightPoint, result))
					{
						booleResult = true;
						*blocking = !VectorsAreEqual(&rectBottomRightPoint, result) && !VectorsAreEqual(&rectTopRightPoint, result);
					}
					else
					{
						booleResult = GetSegmentsIntersection(A, B, &rectTopRightPoint, &rectTopLeftPoint, result);
						*blocking = !VectorsAreEqual(&rectTopRightPoint, result) && !VectorsAreEqual(&rectTopLeftPoint, result);
					}
					break;
				}
			//Что-то пошло не так.
			default:
				{
					//Что-то пошло не так
					break;
				}
		}
	}
	//Обе точки внутри
	else
	{
		//Пока я это проигнорирую. Зачем мне кастовать луч из ящика?
	}
	return booleResult;
}

uint8_t utilites::GetPointCodeCohenSutherland(const sf::Vector2f* const point, const sf::FloatRect* const viewRect)
{
	int result = 0;
	//Точка левее
	if (point->x < viewRect->left)
	{
		result |= (uint8_t)CohenSutherlandCode::Left;
	}
	//Точка правее
	if (point->x > viewRect->left + viewRect->width)
	{
		result |= (uint8_t)CohenSutherlandCode::Right;
	}
	//Точка ниже. Да, это немного сбивает с толку, но раз ось Y идет сверху вниз,
	//то верхняя точка прямоугольника на самом деле нижняя.
	if (point->y < viewRect->top)
	{
		result |= (uint8_t)CohenSutherlandCode::Bottom;
	}
	//Точка выше.
	if (point->y > viewRect->top + viewRect->height)
	{
		result |= (uint8_t)CohenSutherlandCode::Top;
	}
	return result;
}

bool utilites::VectorsAreEqual(const sf::Vector2f* const A, const sf::Vector2f* const B)
{
	return NearZero(A->x - B->x) && NearZero(A->y - B->y);
}

void utilites::GetObjectsInRect(const sf::FloatRect* const rect, const MagicGrid* const grid, ObjectTypeFlags testFlag, MagicGameObjectsConcurrensUnorderedSet*const objectsSet)
{
	//Получение области ячеек по углам прямоугольника
	const size_t leftX = (size_t)floorf(rect->left / grid->GetCellSize());
	const size_t bottomY = (size_t)floorf(rect->top / grid->GetCellSize());
	const size_t rightX = (size_t)floorf((rect->left + rect->width) / grid->GetCellSize());
	const size_t topY = (size_t)floorf((rect->top + rect->height) / grid->GetCellSize());

	objectsSet->clear();

	parallel_for<size_t>(leftX, rightX, 1, [testFlag, grid, objectsSet, bottomY, topY](size_t x)
		{
			parallel_for<size_t>(bottomY, topY, 1, [testFlag, grid, objectsSet, x](size_t y)
				{
					GetObjectsInCell(x, y, grid, testFlag, objectsSet);
				});
		});
	
}

void utilites::GetObjectsInCell(const size_t x, const size_t y, const MagicGrid* const grid, ObjectTypeFlags testFlag, MagicGameObjectsConcurrensUnorderedSet* const objectsSet)
{
	FilterMagicGameObjectsSet(grid->GetCellDynamicObjectsSet(x, y), testFlag, objectsSet);
	FilterMagicGameObjectsSet(grid->GetCellStaticObjectsSet(x, y), testFlag, objectsSet);
}

void utilites::FilterMagicGameObjectsSet(MagicGameObjectsConcurrensUnorderedSet* const originalSet, ObjectTypeFlags testFlag, MagicGameObjectsConcurrensUnorderedSet* const filteredSet)
{
	if (originalSet != nullptr)
	{
		parallel_for_each(originalSet->begin(), originalSet->end(), [filteredSet, testFlag](MagicGameObject* obj)
			{
				if (obj->GetFlags() & (uint16_t)testFlag)
				{
					auto insRes2 = filteredSet->insert(obj);
				}
			});
	}
}

void utilites::GetPointsInRectForRaycast(const sf::Vector2f* const rayStart, const sf::FloatRect* const rect, const MagicGrid* const grid, ObjectTypeFlags testFlag, MagicPointsConcurrensUnorderedSet* const pointsSet)
{
	//Получение области ячеек по углам прямоугольника
	const size_t leftX = (size_t)floorf(rect->left / grid->GetCellSize());
	const size_t bottomY = (size_t)floorf(rect->top / grid->GetCellSize());
	const size_t rightX = (size_t)floorf((rect->left + rect->width) / grid->GetCellSize());
	const size_t topY = (size_t)floorf((rect->top + rect->height) / grid->GetCellSize());

	pointsSet->clear();

	parallel_for<size_t>(leftX, rightX, 1, [rayStart, testFlag, grid, pointsSet, bottomY, topY](size_t x)
		{
			parallel_for<size_t>(bottomY, topY, 1, [rayStart, testFlag, grid, pointsSet, x](size_t y)
				{
					unique_ptr<MagicGameObjectsConcurrensUnorderedSet> allCellObjectsSet = make_unique<MagicGameObjectsConcurrensUnorderedSet>();

					GetObjectsInCell(x, y, grid, testFlag, allCellObjectsSet.get());
					parallel_for_each(allCellObjectsSet->begin(), allCellObjectsSet->end(), [rayStart, pointsSet](MagicGameObject* obj)
						{
							GetPointsInRectForRaycast_HandleGameObject((*it), rayStart, pointsSet);
						});
				});
		});
}

void utilites::GetPointsInRectForRaycast_HandleGameObject(const MagicGameObject* const gameObject, const sf::Vector2f* const rayStart, MagicPointsConcurrensUnorderedSet* const pointsSet)
{
	sf::FloatRect objRect = gameObject->GetRect();
	uint16_t code_a = GetPointCodeCohenSutherland(rayStart, &objRect);
	if (code_a)
	{
		//Точки с разных сторон прямоугольника. Есть смысл заняться проверкой.
		switch (code_a)
		{
			//Источник луча слева от прямоугольника. Достаточно проверить левую грань.
			case (uint8_t)CohenSutherlandCode::Left:
				{
					auto res1 = pointsSet->insert(gameObject->GetTopLeftPoint());
					res1 = pointsSet->insert(gameObject->GetBottomLeftPoint());
					break;
				}
				//Источник луча справа от прямоугольника. Достаточно проверить правую грань.
			case (uint8_t)CohenSutherlandCode::Right:
				{
					auto res1 = pointsSet->insert(gameObject->GetTopRightPoint());
					res1 = pointsSet->insert(gameObject->GetBottomRightPoint());
					break;
				}
				//Источник луча снизу от прямоугольника. Достаточно проверить нижнюю грань.
			case (uint8_t)CohenSutherlandCode::Bottom:
				{
					auto res1 = pointsSet->insert(gameObject->GetBottomLeftPoint());
					res1 = pointsSet->insert(gameObject->GetBottomRightPoint());
					break;
				}
				//Источник луча сверху от прямоугольника. Достаточно проверить верхнюю грань.
			case (uint8_t)CohenSutherlandCode::Top:
				{
					auto res1 = pointsSet->insert(gameObject->GetTopLeftPoint());
					res1 = pointsSet->insert(gameObject->GetTopRightPoint());
					break;
				}
				//Источник луча слева-снизу от прямоугольника. Достаточно проверить левую и нижнюю грани.
			case (uint8_t)CohenSutherlandCode::Left | (uint8_t)CohenSutherlandCode::Bottom:
				{
					auto res1 = pointsSet->insert(gameObject->GetBottomLeftPoint());
					res1 = pointsSet->insert(gameObject->GetBottomRightPoint());
					res1 = pointsSet->insert(gameObject->GetTopLeftPoint());
					break;
				}
				//Источник луча слева-сверху от прямоугольника. Достаточно проверить левую и верхнюю грани.
			case (uint8_t)CohenSutherlandCode::Left | (uint8_t)CohenSutherlandCode::Top:
				{
					auto res1 = pointsSet->insert(gameObject->GetBottomLeftPoint());
					res1 = pointsSet->insert(gameObject->GetTopRightPoint());
					res1 = pointsSet->insert(gameObject->GetTopLeftPoint());
					break;
				}
				//Источник луча справа-снизу от прямоугольника. Достаточно проверить правую и нижнюю грани.
			case (uint8_t)CohenSutherlandCode::Right | (uint8_t)CohenSutherlandCode::Bottom:
				{
					auto res1 = pointsSet->insert(gameObject->GetBottomLeftPoint());
					res1 = pointsSet->insert(gameObject->GetBottomRightPoint());
					res1 = pointsSet->insert(gameObject->GetTopRightPoint());
					break;
				}
				//Источник луча справа-сверху от прямоугольника. Достаточно проверить правую и верхнюю грани.
			case (uint8_t)CohenSutherlandCode::Right | (uint8_t)CohenSutherlandCode::Top:
				{
					auto res1 = pointsSet->insert(gameObject->GetBottomRightPoint());
					res1 = pointsSet->insert(gameObject->GetTopRightPoint());
					res1 = pointsSet->insert(gameObject->GetTopLeftPoint());
					break;
				}
				//Что-то пошло не так.
			default:
				{
					//Что-то пошло не так
					break;
				}
		}
	}
}

bool utilites::RectanglesOverlaping(const sf::FloatRect* const rect1, const sf::FloatRect* const rect2)
{
	if(rect1->top > rect2->top + rect2->height || rect2->top > rect1->top + rect1->height)
		return false;
	if (rect1->left > rect2->left + rect2->width || rect2->left > rect1->left + rect1->width)
		return false;
	return true;
}

void utilites::GetPointsForLightingPoligon(const sf::FloatRect* const view, const sf::Vector2f* const rayStart, const MagicGrid* const grid, concurrent_vector<LightingCollisionPoint>* const pointsSet)
{
	unique_ptr<MagicPointsConcurrensUnorderedSet> set = make_unique<MagicPointsConcurrensUnorderedSet>();

	GetPointsInRectForRaycast(rayStart, view, grid, ObjectTypeFlags::VisibilityBlocking, set.get());
	parallel_for_each(set->begin(), set->end(), [pointsSet, rayStart, view, grid](sf::Vector2f* checkPoint)
		{
			unique_ptr<sf::Vector2f> borderPoint = make_unique<sf::Vector2f>();
			unique_ptr <bool> blocked = make_unique<bool>();
			*blocked = false;
			if (GetRayAndViewBorderIntersectionPoint(rayStart, checkPoint, view, borderPoint.get()))
			{
				vector<utilites::RasterizedCell> cells = RasterizeSegment(rayStart, borderPoint.get(), &(grid->GetOriginPoint()), grid->GetCellSize());
				if (cells.size() > 0)
				{

				}
			}
			if (!*blocked)
			{
				//pointsSet->push_back(LightingCollisionPoint(*borderPoint, *rayStart));
			}
		});

}

vector<utilites::RasterizedCell> utilites::RasterizeSegment(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const gridOriginPoint, const float gridCellSize)
{
	vector<utilites::RasterizedCell> result;
	sf::Vector2f A_temp = *A - *gridOriginPoint;
	sf::Vector2f B_temp = *B - *gridOriginPoint;

	float dx = B_temp.x - A_temp.x;
	float dy = B_temp.y - A_temp.y;
	int startX = (int)floorf(A_temp.x / gridCellSize);
	int startY = (int)floorf(A_temp.y / gridCellSize);
	result.push_back(utilites::RasterizedCell(startX, startY, 0));
	int endX = (int)floorf(B_temp.x / gridCellSize);
	int endY = (int)floorf(B_temp.y / gridCellSize);
	float distance = sqrtf((float)(endX - startX) * (endX - startX) + (float)(endY - startY) * (endY - startY));
	if (startX == endX && startY == endY)
	{
		return result;
	}
	result.push_back(utilites::RasterizedCell(endX, endY, distance));
	if (NearZero(dx) && !NearZero(dy))
	{
		float tempStartY, tempEndY;
		if (A_temp.y > B_temp.y)
		{
			tempStartY = B_temp.y;
			tempEndY = A_temp.y;
		}
		else
		{
			tempStartY = A_temp.y;
			tempEndY = B_temp.y;
		}
		float tempY = tempStartY + gridCellSize;
		int cellX = (int)floorf(A_temp.x / gridCellSize);
		while (tempY < tempEndY)
		{		
			int cellY = (int)floorf(tempY / gridCellSize);
			distance = sqrtf((float)(cellX - startX) * (cellX - startX) + (float)(cellY - startY) * (cellY - startY));
			result.push_back(utilites::RasterizedCell(cellX, cellY, distance));
			tempY += gridCellSize;
		}
	}
	else if (NearZero(dy) && !NearZero(dx))
	{
		float tempStartX, tempEndX;
		if (A_temp.x > B_temp.x)
		{
			tempStartX = B_temp.x;
			tempEndX = A_temp.x;
		}
		else
		{
			tempStartX = A_temp.x;
			tempEndX = B_temp.x;
		}
		float tempX = tempStartX + gridCellSize;
		int cellY = (int)floorf(A_temp.y / gridCellSize);
		while (tempX < tempEndX)
		{
			int cellX = (int)floorf(tempX / gridCellSize);
			distance = sqrtf((float)(cellX - startX) * (cellX - startX) + (float)(cellY - startY) * (cellY - startY));
			result.push_back(utilites::RasterizedCell(cellX, cellY, distance));
			tempX += gridCellSize;
		}
	}
	else
	{
		float k = dy / dx;
		float b = A_temp.y - k * A_temp.x;
		if (fabsf(dx) > fabsf(dy))
		{
			float tempStartX, tempEndX;
			if (A_temp.x > B_temp.x)
			{
				tempStartX = B_temp.x;
				tempEndX = A_temp.x;
			}
			else
			{
				tempStartX = A_temp.x;
				tempEndX = B_temp.x;
			}
			float tempX = tempStartX + gridCellSize;
			while (tempX < tempEndX)
			{
				float tempY = k * tempX + b;
				int cellX = (int)floorf(tempX / gridCellSize);
				int cellY = (int)floorf(tempY / gridCellSize);
				distance = sqrtf((float)(cellX - startX) * (cellX - startX) + (float)(cellY - startY) * (cellY - startY));
				result.push_back(utilites::RasterizedCell(cellX, cellY, distance));
				tempX += gridCellSize;
			}
		}
		else
		{
			float tempStartY, tempEndY;
			if (A_temp.y > B_temp.y)
			{
				tempStartY = B_temp.y;
				tempEndY = A_temp.y;
			}
			else
			{
				tempStartY = A_temp.y;
				tempEndY = B_temp.y;
			}
			float tempY = tempStartY + gridCellSize;
			while (tempY < tempEndY)
			{
				int cellY = (int)floorf(tempY / gridCellSize);
				float tempX = (tempY - b) / k;
				int cellX = (int)floorf(tempX / gridCellSize);
				distance = sqrtf((float)(cellX - startX) * (cellX - startX) + (float)(cellY - startY) * (cellY - startY));
				result.push_back(utilites::RasterizedCell(cellX, cellY, distance));
				tempY += gridCellSize;
			}
		}
	}
	sort(std::begin(result), std::end(result), [](utilites::RasterizedCell a, utilites::RasterizedCell b) {return a.distance < b.distance; });
	return result;
}
