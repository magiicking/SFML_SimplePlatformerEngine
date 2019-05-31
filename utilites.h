#pragma once

#include "pch.h"

using namespace std;
using namespace concurrency;

static class utilites
{
public:
	struct RasterizedCell
	{
	public:
		int x;
		int y;
		float distance;
		RasterizedCell(int _x, int _y, float _distance)
		{
			x = _x;
			y = _y;
			distance = _distance;
		}
	};

	///Скалярное произведение векторов
	static float Dot2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);
	///Векторное произведение векторов
	static float Cross2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);
	///Векторное произведение векторов по трем точкам
	static float CrossAB_AC(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C);
	///Получение по двум точкам коэффициентов параметрического уравнения прямой Ах + Ву + С = 0
	///Если с линией что-то не так, вместо первого коэффициента возвращает НАН
	static bool GetLineByPoints(const sf::Vector2f* const A, const sf::Vector2f* const B, sf::Vector3f* const result);
	///Получение точки пересечения двух линий. Если линии параллельны, возвращает НАН. Если совпадают - бесконечность.
	static bool GetLinesCrossing(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result);
	///Сравнивает модуль числа с эпсилон
	static bool NearZero(float value);
	///Проверяет, находится ли точка на отрезке
	static bool IsPointOnSegment(const sf::Vector2f* const segmentStart, const sf::Vector2f* const segmentEnd, const sf::Vector2f* const point);
	///Получает длину вектора
	static float VectorLenght(const sf::Vector2f* const vect);
	///Получает центр треугольника по трем точкам
	static void GetTriangleCenter(const sf::Vector2f* const a1, const sf::Vector2f* const a2, const sf::Vector2f* const a3, sf::Vector2f* const result);
	///Получает нормаль по двум точкам и центру треугольника.
	static void GetNormal(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const TriangleCenter, sf::Vector2f* const result);

	static vector<RasterizedCell> RasterizeSegment(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const gridOriginPoint, const float gridCellSize);

	static bool GetSegmentsCrossing(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const out);
};

