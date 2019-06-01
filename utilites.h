#pragma once

#include "pch.h"

using namespace std;
using namespace concurrency;

static class utilites
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
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

	template<typename Tval>
	struct PointerHash 
	{
		size_t operator()(const Tval* val) const 
		{
			static const size_t shift = (size_t)log2(1 + sizeof(Tval));
			return (size_t)(val) >> shift;
		}
	};

	template<typename Tval>
	struct PointerComparator
	{
		bool operator()(const Tval* obj1, const Tval* obj2) const
		{
			if (obj1 == obj2)
				return true;
			return false;
		}
	};

	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static float Dot2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static float Cross2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static float CrossAB_AC(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static bool GetLineByPoints(const sf::Vector2f* const A, const sf::Vector2f* const B, sf::Vector3f* const result);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static bool GetLinesCrossing(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static bool NearZero(float value);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static bool IsPointOnSegment(const sf::Vector2f* const segmentStart, const sf::Vector2f* const segmentEnd, const sf::Vector2f* const point);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static float VectorLenght(const sf::Vector2f* const vect);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static void GetTriangleCenter(const sf::Vector2f* const a1, const sf::Vector2f* const a2, const sf::Vector2f* const a3, sf::Vector2f* const result);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static void GetNormal(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const TriangleCenter, sf::Vector2f* const result);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static vector<RasterizedCell> RasterizeSegment(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const gridOriginPoint, const float gridCellSize);
	////////////////////////////////////////////////////////////
	/// \brief Заполнить описание.
	///
	/// 
	/// 
	/// 
	/// \param Параметр     Заполнить параметры.
	///
	////////////////////////////////////////////////////////////
	static bool GetSegmentsCrossing(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const out);
};

