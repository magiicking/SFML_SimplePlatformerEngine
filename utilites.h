#pragma once

#include "pch.h"

using namespace std;
using namespace concurrency;

////////////////////////////////////////////////////////////
/// \brief �����, ���������� ������ �������� ��������� � ���������.
///
/// 
/// 
/// 
/// 
///
////////////////////////////////////////////////////////////
class utilites
{
public:

	

	////////////////////////////////////////////////////////////
	/// \brief ��������������� ������.
	///
	/// ��������� ��� �������� ��������� ������, ����� �������
	/// ������ ���, � ����� ���������� �� ������ ������ ����.
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	struct RasterizedCell
	{
	public:

		////////////////////////////////////////////////////////////
		/// \brief �-���������� ������.
		///
		/// 
		/// 
		/// 
		/// 
		///
		////////////////////////////////////////////////////////////
		int x;

		////////////////////////////////////////////////////////////
		/// \brief �-���������� ������.
		///
		/// 
		/// 
		/// 
		/// 
		///
		////////////////////////////////////////////////////////////
		int y;

		////////////////////////////////////////////////////////////
		/// \brief ���������� �� ������ ������ ����.
		///
		/// 
		/// 
		/// 
		/// 
		///
		////////////////////////////////////////////////////////////
		float distance;

		////////////////////////////////////////////////////////////
		/// \brief �����������.
		///
		/// 
		/// 
		/// 
		/// \param _x     �-���������� ������.
		/// \param _y     �-���������� ������.
		/// \param _distance     ���������� �� ������ ������ ����.
		///
		////////////////////////////////////////////////////////////
		RasterizedCell(int _x, int _y, float _distance)
		{
			x = _x;
			y = _y;
			distance = _distance;
		}
	};

	////////////////////////////////////////////////////////////
	/// \brief ���-������� ����������.
	///
	/// ���� ������ ���������, �� ���� ����� �������.
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
	template<typename Tval>
	struct PointerHash 
	{
		size_t operator()(const Tval* val) const 
		{
			static const size_t shift = (size_t)log2(1 + sizeof(Tval));
			return (size_t)(val) >> shift;
		}
	};

	////////////////////////////////////////////////////////////
	/// \brief ��������� ����������.
	///
	/// ������-�� ������� ��������� � ����� � ���� �� �����������.
	/// 
	/// 
	/// 
	///
	////////////////////////////////////////////////////////////
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
	/// \brief ��������� ������������ ���� ��������.
	///
	/// ���� ��� ����� ����, �� ������� ���������������.
	/// ���� ��� ������ ����, �� ��� ������������.
	/// ���� ��� ������ ����, �� ������� �������������� ����������.
	/// 
	/// \param vector1     ������ ������.
	/// \param vector2     ������ ������.
	///
	////////////////////////////////////////////////////////////
	static float Dot2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ������������ ���� ��������.
	///
	/// ���� ��� ����� ����, �� ������� ����������� (�����������, �� �����
	/// �������� � ��������������� �������).
	/// 
	/// \param vector1     ������ ������.
	/// \param vector2     ������ ������.
	///
	////////////////////////////////////////////////////////////
	static float Cross2d(const sf::Vector2f* const vector1, const sf::Vector2f* const vector2);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ������������ ���� ��������.
	///
	/// ���� ��� ����� ����, �� ������� ����������� (�����������, �� �����
	/// �������� � ��������������� �������).
	/// �������: �� = � - �, �� = � - �.
	/// 
	/// \param �     ����� "������" ��������.
	/// \param �     ����� ����� ������� �������.
	/// \param �     ����� ����� ������� �������.
	///
	////////////////////////////////////////////////////////////
	static float CrossAB_AC(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ������ �� ���� ������.
	///
	/// ���� ������ �������� �� �������, �� ���������� ����.
	/// 
	/// 
	/// \param �     ������ �����.
	/// \param �     ������ �����.
	/// \param result     ������-���������: x,y,z - ��������������, ������������ �, �, � ������.
	///
	////////////////////////////////////////////////////////////
	static bool GetLineByPoints(const sf::Vector2f* const A, const sf::Vector2f* const B, sf::Vector3f* const result);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ����������� ���� ������.
	///
	/// ���� ������ ������������, �� ���������� ������, � � ��������� ������������ �����.
	/// ���� ������ ����������� � ���������, �� ���������� ������, � � ��������� ������������ �������������.
	/// ���� ������ ����������� � �� ���������, �� ���������� ����, � � ��������� ������������� NAN
	/// 
	/// \param line1     ������������ ������ ������.
	/// \param line2     ������������ ������ ������.
	/// \param result     ������-���������. ����� �����������, ���� �������������, ���� NAN.
	///
	////////////////////////////////////////////////////////////
	static bool GetLinesCrossing(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������� ����� � ��������� ������� � �����.
	///
	/// ���� ������ ����� ������ �������, �� ���������� ������, ����� ����.
	/// 
	/// 
	/// \param value     ����������� �����.
	///
	////////////////////////////////////////////////////////////
	static bool NearZero(float value);

	////////////////////////////////////////////////////////////
	/// \brief ���������, ����������� �� ����� �������.
	///
	/// ���� � � �-���������� ����� ����� ������� � ������ �������,
	/// � ������� �� ������ ������� � ����� � �� ������ ������� � �����
	/// �����������, �� ����� ����� �� �������.
	/// 
	/// \param segmentStart     ����� ������ �������.
	/// \param segmentEnd     ����� ����� �������.
	/// \param point     ���������� �����.
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

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetRayAndViewBorderCrossingPoint(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::FloatRect* const viewRect, sf::Vector2f* const result);
};

