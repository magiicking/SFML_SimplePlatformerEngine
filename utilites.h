#pragma once

#include "pch.h"

using namespace std;
using namespace concurrency;

static class utilites
{
public:
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
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

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static float Dot2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static float Cross2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static float CrossAB_AC(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetLineByPoints(const sf::Vector2f* const A, const sf::Vector2f* const B, sf::Vector3f* const result);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetLinesCrossing(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool NearZero(float value);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool IsPointOnSegment(const sf::Vector2f* const segmentStart, const sf::Vector2f* const segmentEnd, const sf::Vector2f* const point);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static float VectorLenght(const sf::Vector2f* const vect);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static void GetTriangleCenter(const sf::Vector2f* const a1, const sf::Vector2f* const a2, const sf::Vector2f* const a3, sf::Vector2f* const result);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static void GetNormal(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const TriangleCenter, sf::Vector2f* const result);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static vector<RasterizedCell> RasterizeSegment(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const gridOriginPoint, const float gridCellSize);
	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetSegmentsCrossing(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const out);
};

