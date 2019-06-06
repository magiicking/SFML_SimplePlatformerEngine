#include "pch.h"

#include "CppUnitTest.h"
#include "../utilites.h"
#include "../MagicGameObject.h"
#include "../MagicGrid.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySimlpePlatformerEngineTests
{
	/*TEST_CLASS(MySimlpePlatformerEngineTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}
	};*/

	TEST_CLASS(utilites_test)
	{
	public:

		TEST_METHOD(GetRayAndViewBorderIntersectionPoint)
		{
			sf::FloatRect rect = sf::FloatRect(0.0f, 0.0f, 6.0f, 4.0f);
			sf::Vector2f startPoint = sf::Vector2f(3.0f, 1.0f);
			sf::Vector2f startPoint2 = sf::Vector2f(300.0f, 1.0f);
			sf::Vector2f endPoint1 = sf::Vector2f(1.0f, 1.0f);
			sf::Vector2f endPoint2 = sf::Vector2f(2.5f, 0.5f);
			sf::Vector2f endPoint3 = sf::Vector2f(4.0f, 0.5f);
			sf::Vector2f endPoint4 = sf::Vector2f(1.0f, 3.0f);
			sf::Vector2f endPoint5 = sf::Vector2f(4.5f, 1.5f);
			sf::Vector2f endPoint6 = sf::Vector2f(3.0f, 2.0f);
			sf::Vector2f result1 = sf::Vector2f(0.0f, 1.0f);
			sf::Vector2f result2 = sf::Vector2f(2.0f, 0.0f);
			sf::Vector2f result3 = sf::Vector2f(5.0f, 0.0f);
			sf::Vector2f result4 = sf::Vector2f(0.0f, 4.0f);
			sf::Vector2f result5 = sf::Vector2f(6.0f, 2.0f);
			sf::Vector2f result6 = sf::Vector2f(3.0f, 4.0f);
			sf::Vector2f result7 = sf::Vector2f(0.0f, 2.01010108f);
			sf::Vector2f result = sf::Vector2f();
			bool success = false;
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &endPoint1, &rect, &result);
			Assert::IsTrue(success);
			
			Assert::AreEqual(result1.x, result.x);
			Assert::AreEqual(result1.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &endPoint2, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result2.x, result.x);
			Assert::AreEqual(result2.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &endPoint3, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result3.x, result.x);
			Assert::AreEqual(result3.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &endPoint4, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result4.x, result.x);
			Assert::AreEqual(result4.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &endPoint5, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result5.x, result.x);
			Assert::AreEqual(result5.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &endPoint6, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result6.x, result.x);
			Assert::AreEqual(result6.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint2, &endPoint6, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result7.x, result.x);
			Assert::AreEqual(result7.y, result.y);
			success = utilites::GetRayAndViewBorderIntersectionPoint(&startPoint, &startPoint, &rect, &result);
			Assert::IsFalse(success);
			//Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Dot2d)
		{
			sf::Vector2f vector1 = sf::Vector2f(2.0f, 2.0f);
			sf::Vector2f vector2 = sf::Vector2f(2.0f, -2.0f);
			float result = 0.0f;
			result = utilites::Dot2d(&vector1, &vector2);
			Assert::AreEqual(0.0f, result);

			vector1 = sf::Vector2f(2.0f, 2.0f);
			vector2 = sf::Vector2f(2.0f, 0.0f);
			result = utilites::Dot2d(&vector1, &vector2);
			Assert::AreEqual(4.0f, result);

			vector1 = sf::Vector2f(2.0f, 2.0f);
			vector2 = sf::Vector2f(-2.0f, -1.0f);
			result = utilites::Dot2d(&vector1, &vector2);
			Assert::AreEqual(-6.0f, result);
		}

		TEST_METHOD(Cross2d)
		{
			sf::Vector2f vector1 = sf::Vector2f(2.0f, 2.0f);
			sf::Vector2f vector2 = sf::Vector2f(2.0f, -2.0f);
			float result = 0.0f;
			result = utilites::Cross2d(&vector1, &vector2);
			Assert::AreEqual(-8.0f, result);

			vector1 = sf::Vector2f(2.0f, 2.0f);
			vector2 = sf::Vector2f(2.0f, 0.0f);
			result = utilites::Cross2d(&vector1, &vector2);
			Assert::AreEqual(-4.0f, result);

			vector1 = sf::Vector2f(2.0f, 2.0f);
			vector2 = sf::Vector2f(-2.0f, -1.0f);
			result = utilites::Cross2d(&vector1, &vector2);
			Assert::AreEqual(2.0f, result);
		}

		TEST_METHOD(CrossAB_AC)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 1.0f);
			sf::Vector2f B = sf::Vector2f(3.0f, 3.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, -1.0f);
			float result = 0.0f;
			result = utilites::CrossAB_AC(&A, &B, &C);
			Assert::AreEqual(-8.0f, result);

			B = sf::Vector2f(3.0f, 3.0f);
			C = sf::Vector2f(3.0f, 1.0f);
			result = utilites::CrossAB_AC(&A, &B, &C);
			Assert::AreEqual(-4.0f, result);

			B = sf::Vector2f(3.0f, 3.0f);
			C = sf::Vector2f(-1.0f, -0.0f);
			result = utilites::CrossAB_AC(&A, &B, &C);
			Assert::AreEqual(2.0f, result);
		}

		TEST_METHOD(GetLineByPoints)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 1.0f);
			sf::Vector2f B = sf::Vector2f(3.0f, 3.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, -1.0f);
			sf::Vector3f result = sf::Vector3f();
			Assert::IsTrue(utilites::GetLineByPoints(&A, &B, &result));
			Assert::AreEqual(-2.0f, result.x);
			Assert::AreEqual(2.0f, result.y);
			Assert::AreEqual(0.0f, result.z);

			Assert::IsTrue(utilites::GetLineByPoints(&A, &C, &result));
			Assert::AreEqual(2.0f, result.x);
			Assert::AreEqual(2.0f, result.y);
			Assert::AreEqual(-4.0f, result.z);

			Assert::IsFalse(utilites::GetLineByPoints(&A, &A, &result));
		}

		TEST_METHOD(GetLinesIntersection1)
		{
			sf::Vector3f line1 = sf::Vector3f(-2.0f, 2.0f, 0.0f);
			sf::Vector3f line2 = sf::Vector3f(2.0f, 2.0f, -4.0f);
			sf::Vector3f line3 = sf::Vector3f(2.0f, 2.0f, -5.0f);
			sf::Vector2f result = sf::Vector2f();

			Assert::IsTrue(utilites::GetLinesIntersection(&line1, &line2, &result));
			Assert::AreEqual(1.0f, result.x);
			Assert::AreEqual(1.0f, result.y);


			Assert::IsTrue(utilites::GetLinesIntersection(&line1, &line3, &result));
			Assert::AreEqual(1.25f, result.x);
			Assert::AreEqual(1.25f, result.y);


			Assert::IsFalse(utilites::GetLinesIntersection(&line3, &line2, &result));
			Assert::IsTrue(isnan(result.x));
			Assert::IsTrue(isnan(result.y));

			Assert::IsTrue(utilites::GetLinesIntersection(&line1, &line1, &result));
			Assert::IsTrue(isinf(result.x));
			Assert::IsTrue(isinf(result.y));
		}

		TEST_METHOD(GetLinesIntersection2)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 1.0f);
			sf::Vector2f B = sf::Vector2f(3.0f, 3.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, -1.0f);
			sf::Vector2f result = sf::Vector2f();

			Assert::IsTrue(utilites::GetLinesIntersection(&A, &B, &C, &A, &result));
			Assert::AreEqual(1.0f, result.x);
			Assert::AreEqual(1.0f, result.y);

			Assert::IsFalse(utilites::GetLinesIntersection(&A, &B, &B, &A, &result));
			
		}

		TEST_METHOD(NearZero)
		{
			Assert::IsTrue(utilites::NearZero(1.0f - 1.0f));
			Assert::IsFalse(utilites::NearZero(1.000001f - 1.0f));
		}

		TEST_METHOD(IsPointOnSegment)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 1.0f);
			sf::Vector2f B = sf::Vector2f(5.0f, 5.0f);
			sf::Vector2f C = sf::Vector2f(2.0f, 2.0f);
			sf::Vector2f D = sf::Vector2f(6.0f, 6.0f);
			sf::Vector2f E = sf::Vector2f(4.0f, 2.0f);
			Assert::IsTrue(utilites::IsPointOnSegment(&A, &B, &C));
			Assert::IsFalse(utilites::IsPointOnSegment(&A, &B, &D));
			Assert::IsFalse(utilites::IsPointOnSegment(&A, &B, &E));
		}

		TEST_METHOD(VectorLenght)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 1.0f);
			sf::Vector2f B = sf::Vector2f(5.0f, 5.0f);
			sf::Vector2f C = sf::Vector2f(2.0f, 2.0f);
			Assert::AreEqual(sqrtf(2.0f), utilites::VectorLenght(&A));
			Assert::AreEqual(sqrtf(50.0f), utilites::VectorLenght(&B));
			Assert::AreEqual(sqrtf(8.0f), utilites::VectorLenght(&C));
		}

		TEST_METHOD(GetTriangleCenter)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 3.0f);
			sf::Vector2f B = sf::Vector2f(2.0f, 1.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, 2.0f);
			sf::Vector2f center = sf::Vector2f();
			utilites::GetTriangleCenter(&A, &B, &C, &center);
			Assert::AreEqual(2.0f, center.x);
			Assert::AreEqual(2.0f, center.y);
		}

		TEST_METHOD(GetNormal)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 3.0f);
			sf::Vector2f B = sf::Vector2f(2.0f, 1.0f);
			sf::Vector2f center = sf::Vector2f(2.0f, 2.0f);
			sf::Vector2f normal = sf::Vector2f();
			utilites::GetNormal(&A, &B, &center, &normal);

			Assert::AreEqual(-2.0f / sqrtf(5.0f), normal.x);
			Assert::AreEqual(-1.0f / sqrtf(5.0f), normal.y);

			center = sf::Vector2f(-2.0f, -2.0f);
			utilites::GetNormal(&A, &B, &center, &normal);

			Assert::AreEqual(2.0f / sqrtf(5.0f), normal.x);
			Assert::AreEqual(1.0f / sqrtf(5.0f), normal.y);
		}

		TEST_METHOD(RasterizeSegment)
		{
			sf::Vector2f A = sf::Vector2f(0.0f, 0.0f);
			sf::Vector2f B = sf::Vector2f(300.0f, 300.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, -1.0f);
			sf::Vector2f gridOrigin = sf::Vector2f(0.0f, 0.0f);
			float gridCellSize = 100.0f;

			vector<utilites::RasterizedCell> result = utilites::RasterizeSegment(&A, &B, &gridOrigin, gridCellSize);
			Assert::AreEqual(4, (int)result.size());


			result = utilites::RasterizeSegment(&A, &C, &gridOrigin, gridCellSize);
			Assert::AreEqual(2, (int)result.size());

			result = utilites::RasterizeSegment(&A, &A, &gridOrigin, gridCellSize);
			Assert::AreEqual(1, (int)result.size());
		}

		TEST_METHOD(GetSegmentsIntersection)
		{
			sf::Vector2f A = sf::Vector2f(0.0f, 0.0f);
			sf::Vector2f B = sf::Vector2f(3.0f, 3.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, -1.0f);
			sf::Vector2f D = sf::Vector2f(0.0f, 2.0f);
			sf::Vector2f result = sf::Vector2f();

			Assert::IsTrue(utilites::GetSegmentsIntersection(&A, &B, &C, &D, &result));
			Assert::AreEqual(1.0f, result.x);
			Assert::AreEqual(1.0f, result.y);

			A = sf::Vector2f(1.0f, 1.0f);
			Assert::IsTrue(utilites::GetSegmentsIntersection(&A, &B, &C, &D, &result));
			Assert::AreEqual(1.0f, result.x);
			Assert::AreEqual(1.0f, result.y);

			A = sf::Vector2f(1.01f, 1.01f);
			Assert::IsFalse(utilites::GetSegmentsIntersection(&A, &B, &C, &D, &result));
			
		}

		TEST_METHOD(GetPointCodeCohenSutherland)
		{
			sf::FloatRect rect = sf::FloatRect(10.0f, 10.0f, 20.0f, 20.0f);
			sf::Vector2f Left = sf::Vector2f(0.0f, 15.0f);
			sf::Vector2f Right = sf::Vector2f(31.0f, 15.0f);
			sf::Vector2f Top = sf::Vector2f(15.0f, 31.0f);
			sf::Vector2f Bottom = sf::Vector2f(15.0f, 0.0f);
			sf::Vector2f LeftTop = sf::Vector2f(0.0f, 31.0f);
			sf::Vector2f LeftBottom = sf::Vector2f(0.0f, 0.0f);
			sf::Vector2f RightTop = sf::Vector2f(31.0f, 31.0f);
			sf::Vector2f RightBottom = sf::Vector2f(31.0f, 0.0f);
			sf::Vector2f Inside = sf::Vector2f(15.0f, 15.0f);

			Assert::AreEqual(0b0000, (int)utilites::GetPointCodeCohenSutherland(&Inside, &rect));
			Assert::AreEqual(0b0001, (int)utilites::GetPointCodeCohenSutherland(&Left, &rect));
			Assert::AreEqual(0b0010, (int)utilites::GetPointCodeCohenSutherland(&Right, &rect));
			Assert::AreEqual(0b0100, (int)utilites::GetPointCodeCohenSutherland(&Bottom, &rect));
			Assert::AreEqual(0b1000, (int)utilites::GetPointCodeCohenSutherland(&Top, &rect));
			Assert::AreEqual(0b1001, (int)utilites::GetPointCodeCohenSutherland(&LeftTop, &rect));
			Assert::AreEqual(0b0101, (int)utilites::GetPointCodeCohenSutherland(&LeftBottom, &rect));
			Assert::AreEqual(0b1010, (int)utilites::GetPointCodeCohenSutherland(&RightTop, &rect));
			Assert::AreEqual(0b0110, (int)utilites::GetPointCodeCohenSutherland(&RightBottom, &rect));
		}

		TEST_METHOD(GetRayAndRectCollisionPoint)
		{
			sf::FloatRect rect = sf::FloatRect(0.0f, 0.0f, 6.0f, 4.0f);
			sf::Vector2f Start = sf::Vector2f(0.5f, -1.0f);
			sf::Vector2f Start2 = sf::Vector2f(-1.0f, -1.0f);
			sf::Vector2f A = sf::Vector2f(-1.0f, 0.5f);
			sf::Vector2f B = sf::Vector2f(-0.5f, 1.0f);
			sf::Vector2f C = sf::Vector2f(7.5f, -1.0f);
			sf::Vector2f D = sf::Vector2f(6.0f, 2.0f);
			sf::Vector2f E = sf::Vector2f(1.5f, 5.0f);
			sf::Vector2f F = sf::Vector2f(1.0f, 1.0f);
			
			sf::Vector2f result = sf::Vector2f();
			bool blocking = false;
			bool hasHit = false;

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start, &A, &rect, &result, &blocking);
			Assert::IsFalse(hasHit);

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start, &B, &rect, &result, &blocking);
			Assert::IsTrue(hasHit);
			Assert::IsFalse(blocking);
			Assert::AreEqual(0.0f, result.x);
			Assert::AreEqual(0.0f, result.y);

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start, &C, &rect, &result, &blocking);
			Assert::IsFalse(hasHit);

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start, &D, &rect, &result, &blocking);
			Assert::IsTrue(hasHit);
			Assert::IsTrue(blocking);
			Assert::AreEqual(2.0f + 1.0f/3.0f, result.x);
			Assert::AreEqual(0.0f, result.y);

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start, &E, &rect, &result, &blocking);
			Assert::IsTrue(hasHit);
			Assert::IsTrue(blocking);
			Assert::AreEqual(2.0f / 3.0f, result.x);
			Assert::AreEqual(0.0f, result.y);

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start, &Start, &rect, &result, &blocking);
			Assert::IsFalse(hasHit);

			hasHit = utilites::GetRayAndRectCollisionPoint(&Start2, &F, &rect, &result, &blocking);
			Assert::IsTrue(hasHit);
			Assert::IsTrue(blocking);
			Assert::AreEqual(0.0f, result.x);
			Assert::AreEqual(0.0f, result.y);
		}

		TEST_METHOD(VectorsAreEqual)
		{
			sf::Vector2f A = sf::Vector2f(1.0f, 2.0f);
			sf::Vector2f B = sf::Vector2f(2.0f, 2.0f);
			sf::Vector2f C = sf::Vector2f(-1.0f, -2.0f);
			sf::Vector2f D = sf::Vector2f(1.0f, 2.0f);
			Assert::IsFalse(utilites::VectorsAreEqual(&A, &B));
			Assert::IsFalse(utilites::VectorsAreEqual(&A, &C));
			Assert::IsTrue(utilites::VectorsAreEqual(&A, &D));
			Assert::IsTrue(utilites::VectorsAreEqual(&A, &A));
		}

		TEST_METHOD(GetObjectsInRect)
		{
			//Assert::IsFalse(true);
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			unique_ptr<MagicGameObject> gameObj2 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 300.0f, 200.0f, 200.0f));
			grid->AddStaticObject(gameObj1.get());
			grid->AddStaticObject(gameObj2.get());
			sf::FloatRect checkRect1 = sf::FloatRect(0.0f, 0.0f, 200.0f, 200.0f);
			sf::FloatRect checkRect2 = sf::FloatRect(400.0f, 400.0f, 200.0f, 200.0f);
			sf::FloatRect checkRect3 = sf::FloatRect(0.0f, 0.0f, 500.0f, 500.0f);

			unique_ptr<utilites::MagicGameObjectsConcurrensUnorderedSet> set = make_unique<utilites::MagicGameObjectsConcurrensUnorderedSet>();

			utilites::GetObjectsInRect(&checkRect1, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::IsTrue(set->find(gameObj1.get()) != set->end());
			Assert::IsTrue(set->find(gameObj2.get()) == set->end());

			utilites::GetObjectsInRect(&checkRect2, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::IsTrue(set->find(gameObj1.get()) == set->end());
			Assert::IsTrue(set->find(gameObj2.get()) == set->end());

			utilites::GetObjectsInRect(&checkRect3, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::IsTrue(set->find(gameObj1.get()) != set->end());
			Assert::IsTrue(set->find(gameObj2.get()) != set->end());
			
		}

		TEST_METHOD(GetPointsInRectForRaycast)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			unique_ptr<MagicGameObject> gameObj2 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 300.0f, 200.0f, 200.0f));
			grid->AddStaticObject(gameObj1.get());
			grid->AddStaticObject(gameObj2.get());
			sf::FloatRect checkRect1 = sf::FloatRect(0.0f, 0.0f, 200.0f, 200.0f);
			sf::FloatRect checkRect2 = sf::FloatRect(400.0f, 400.0f, 200.0f, 200.0f);
			sf::FloatRect checkRect3 = sf::FloatRect(0.0f, 0.0f, 500.0f, 500.0f);
			sf::Vector2f rayStart = sf::Vector2f(1.0f, 100.0f);

			unique_ptr<utilites::MagicPointsConcurrensUnorderedSet> set = make_unique<utilites::MagicPointsConcurrensUnorderedSet>();

			utilites::GetPointsInRectForRaycast(&rayStart, &checkRect1, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());			
			Assert::AreEqual(2, (int)set->size());

			utilites::GetPointsInRectForRaycast(&rayStart, &checkRect2, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::AreEqual(0, (int)set->size());

			utilites::GetPointsInRectForRaycast(&rayStart, &checkRect3, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::AreEqual(5, (int)set->size());
		}

		TEST_METHOD(GetPointsInRectForRaycast_HandleGameObject)
		{
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 300.0f, 200.0f, 200.0f));
			unique_ptr<utilites::MagicPointsConcurrensUnorderedSet> set = make_unique<utilites::MagicPointsConcurrensUnorderedSet>();
			sf::Vector2f rayStart = sf::Vector2f(1.0f, 100.0f);

			utilites::GetPointsInRectForRaycast_HandleGameObject(gameObj1.get(), &rayStart, set.get());

			Assert::AreEqual(3, (int)set->size());
		}

		TEST_METHOD(RectanglesOverlaping)
		{
			sf::FloatRect rect1 = sf::FloatRect(0.0f, 0.0f, 5.0f, 5.0f);
			sf::FloatRect rect2 = sf::FloatRect(2.0f, 2.0f, 7.0f, 7.0f);
			sf::FloatRect rect3 = sf::FloatRect(-1.0f, 0.0f, 5.0f, 6.0f);
			sf::FloatRect rect4 = sf::FloatRect(5.1f, 5.1f, 5.0f, 5.0f);
			Assert::IsTrue(rect1.intersects(rect2));
			Assert::IsTrue(utilites::RectanglesOverlaping(&rect1, &rect2));
			Assert::IsTrue(rect1.intersects(rect3));
			Assert::IsTrue(utilites::RectanglesOverlaping(&rect1, &rect3));
			Assert::IsFalse(rect1.intersects(rect4));
			Assert::IsFalse(utilites::RectanglesOverlaping(&rect1, &rect4));
		}
	
		TEST_METHOD(GetObjectsInCell)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			unique_ptr<MagicGameObject> gameObj2 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 300.0f, 200.0f, 200.0f));
			grid->AddStaticObject(gameObj1.get());
			grid->AddStaticObject(gameObj2.get());

			unique_ptr<utilites::MagicGameObjectsConcurrensUnorderedSet> set = make_unique<utilites::MagicGameObjectsConcurrensUnorderedSet>();

			utilites::GetObjectsInCell(1, 0, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::IsTrue(set->find(gameObj1.get()) != set->end());
			Assert::IsTrue(set->find(gameObj2.get()) == set->end());

			set->clear();

			utilites::GetObjectsInCell(1, 3, grid.get(), ObjectTypeFlags::VisibilityBlocking, set.get());
			Assert::IsTrue(set->find(gameObj1.get()) == set->end());
			Assert::IsTrue(set->find(gameObj2.get()) != set->end());

			//Assert::IsFalse(true);
		}

		TEST_METHOD(FilterMagicGameObjectsSet)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			unique_ptr<MagicGameObject> gameObj2 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 300.0f, 200.0f, 200.0f));
			grid->AddStaticObject(gameObj1.get());
			grid->AddStaticObject(gameObj2.get());

			unique_ptr<utilites::MagicGameObjectsConcurrensUnorderedSet> set2 = make_unique<utilites::MagicGameObjectsConcurrensUnorderedSet>();

			utilites::MagicGameObjectsConcurrensUnorderedSet* set = grid->GetCellStaticObjectsSet(1, 0);
			Assert::AreEqual(1, (int)set->size());

			utilites::FilterMagicGameObjectsSet(set, ObjectTypeFlags::VisibilityBlocking, set2.get());
			Assert::AreEqual(1, (int)set2->size());

			set2->clear();

			utilites::FilterMagicGameObjectsSet(set, ObjectTypeFlags::Trigger, set2.get());
			Assert::AreEqual(0, (int)set2->size());
		}

		TEST_METHOD(GetPointsForLightingPoligon)
		{

			Assert::IsFalse(true);
		}
	};

	TEST_CLASS(grid_test)
	{

		TEST_METHOD(GetCellSize)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);

			Assert::AreEqual(100.0f, grid->GetCellSize());
		}

		TEST_METHOD(AddStaticObject)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			Assert::IsTrue(grid->AddStaticObject(gameObj1.get()));
			Assert::IsFalse(grid->AddStaticObject(gameObj1.get()));
		}

		TEST_METHOD(AddDynamicObject)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			Assert::IsTrue(grid->AddDynamicObject(gameObj1.get()));
			Assert::IsFalse(grid->AddDynamicObject(gameObj1.get()));
		}

		TEST_METHOD(GetCellStaticObjectsSet)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			grid->AddStaticObject(gameObj1.get());
			utilites::MagicGameObjectsConcurrensUnorderedSet* set = grid->GetCellStaticObjectsSet(1, 0);
			Assert::IsFalse(set->find(gameObj1.get()) == set->end());
			set = grid->GetCellStaticObjectsSet(1, 1);
			Assert::IsFalse(set->find(gameObj1.get()) == set->end());
			set = grid->GetCellStaticObjectsSet(0, 0);
			Assert::IsTrue(set->find(gameObj1.get()) == set->end());
			set = grid->GetCellStaticObjectsSet(100, 0);
			Assert::IsNull(set);
		}

		TEST_METHOD(GetCellDynamicObjectsSet)
		{
			unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(5, 5, 100.0f);
			unique_ptr<MagicGameObject> gameObj1 = make_unique<MagicGameObject>(sf::FloatRect(101.0f, 0.0f, 200.0f, 200.0f));
			grid->AddDynamicObject(gameObj1.get());
			utilites::MagicGameObjectsConcurrensUnorderedSet* set = grid->GetCellDynamicObjectsSet(1, 0);
			Assert::IsFalse(set->find(gameObj1.get()) == set->end());
			set = grid->GetCellDynamicObjectsSet(1, 1);
			Assert::IsFalse(set->find(gameObj1.get()) == set->end());
			set = grid->GetCellDynamicObjectsSet(0, 0);
			Assert::IsTrue(set->find(gameObj1.get()) == set->end());
			set = grid->GetCellStaticObjectsSet(100, 0);
			Assert::IsNull(set);
		}
	};
}
