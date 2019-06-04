#pragma once

#include "pch.h"

using namespace std;
using namespace concurrency;

class MagicGrid;
class MagicGameObject;
enum class ObjectTypeFlags : uint16_t;

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
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	enum class CohenSutherlandCode : uint8_t
	{
		Inside = 0b0000,
		Left = 0b0001,
		Right = 0b0010,
		Bottom = 0b0100,
		Top = 0b1000
	};

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
	static bool GetLinesIntersection(const sf::Vector3f* const line1, const sf::Vector3f* const line2, sf::Vector2f* const result);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetLinesIntersection(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const result);

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
	static bool GetSegmentsIntersection(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::Vector2f* const C, const sf::Vector2f* const D, sf::Vector2f* const out);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetRayAndViewBorderIntersectionPoint(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::FloatRect* const viewRect, sf::Vector2f* const result);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool GetRayAndRectCollisionPoint(const sf::Vector2f* const A, const sf::Vector2f* const B, const sf::FloatRect* const viewRect, sf::Vector2f* const result, bool * const blocking);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static uint8_t GetPointCodeCohenSutherland(const sf::Vector2f* const point, const sf::FloatRect* const rect);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static bool VectorsAreEqual(const sf::Vector2f* const A, const sf::Vector2f* const B);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static void GetObjectsInRect(const sf::FloatRect* const rect, const MagicGrid* const grid, ObjectTypeFlags testFlag, concurrent_unordered_set<MagicGameObject*,
		utilites::PointerHash<MagicGameObject>,
		utilites::PointerComparator<MagicGameObject>>* const objectsSet);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static void GetPointsInRectForRaycast(const sf::Vector2f* const rayStart, const sf::FloatRect* const rect,
		const MagicGrid* const grid,
		ObjectTypeFlags testFlag, concurrent_unordered_set<sf::Vector2f*,utilites::PointerHash<sf::Vector2f>,utilites::PointerComparator<sf::Vector2f>>* const pointsSet);

	////////////////////////////////////////////////////////////
	/// \brief ��������� ��������.
	///
	/// 
	/// 
	/// 
	/// \param ��������     ��������� ���������.
	///
	////////////////////////////////////////////////////////////
	static void GetPointsInRectForRaycast_HandleGameObject(const MagicGameObject* const gameObject, const sf::Vector2f* const rayStart, concurrent_unordered_set<sf::Vector2f*, utilites::PointerHash<sf::Vector2f>, utilites::PointerComparator<sf::Vector2f>>* const pointsSet);
};

