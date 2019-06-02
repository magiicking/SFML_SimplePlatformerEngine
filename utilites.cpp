#include "pch.h"
#include "utilites.h"

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

bool utilites::GetLinesCrossing(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result)
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
				result->x = std::numeric_limits<float>::quiet_NaN();
				result->y = std::numeric_limits<float>::quiet_NaN();
				return false;
			}
			else
			{
				result->x = std::numeric_limits<float>::infinity();
				result->y = std::numeric_limits<float>::infinity();
				return true;
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

bool utilites::GetSegmentsCrossing(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const out)
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
	unique_ptr<sf::Vector3f> line1 = make_unique<sf::Vector3f>();
	unique_ptr<sf::Vector3f> line2 = make_unique<sf::Vector3f>();
	if (GetLineByPoints(A_temp, B_temp, line1.get()) && GetLineByPoints(C_temp, D_temp, line2.get()))
	{
		if (GetLinesCrossing(line1.get(), line2.get(), out))
		{
			if (!isfinite(out->x))
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
			else
			{
				return IsPointOnSegment(A_temp, B_temp, out) && IsPointOnSegment(C_temp, D_temp, out);
			}
		}
	}

	return false;
}

bool utilites::GetRayAndViewBorderCrossingPoint(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::FloatRect* const viewRect, sf::Vector2f* const result)
{
	sf::Vector2f direction = *B - *A;
	direction /= VectorLenght(&direction);
	if (A->x < viewRect->left || A->x > viewRect->left + viewRect->width
		|| A->y < viewRect->top || A->y > viewRect->top + viewRect->height)
	{
		return false;
	}
	float borderX = 0.0f;
	float borderY = 0.0f;
	float borderDirectionX = 0.0f;
	float borderDirectionY = 0.0f;
	if (NearZero(direction.x) && NearZero(direction.y))
	{
		return false;
	}
	else if (NearZero(direction.x))
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
