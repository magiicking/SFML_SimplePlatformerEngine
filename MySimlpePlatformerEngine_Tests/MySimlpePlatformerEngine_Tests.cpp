#include "pch.h"
#include "CppUnitTest.h"
#include "../utilites.h"
#include "../utilites.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MySimlpePlatformerEngineTests
{
	TEST_CLASS(MySimlpePlatformerEngineTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, 1);
		}
	};

	TEST_CLASS(utilites_test)
	{
	public:

		TEST_METHOD(GetRayAndViewBorderCrossingPoint)
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
			sf::Vector2f result = sf::Vector2f();
			bool success = false;
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint1, &rect, &result);
			Assert::IsTrue(success);
			
			Assert::AreEqual(result1.x, result.x);
			Assert::AreEqual(result1.y, result.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint2, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result2.x, result.x);
			Assert::AreEqual(result2.y, result.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint3, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result3.x, result.x);
			Assert::AreEqual(result3.y, result.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint4, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result4.x, result.x);
			Assert::AreEqual(result4.y, result.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint5, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result5.x, result.x);
			Assert::AreEqual(result5.y, result.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint6, &rect, &result);
			Assert::IsTrue(success);
			Assert::AreEqual(result6.x, result.x);
			Assert::AreEqual(result6.y, result.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint2, &endPoint6, &rect, &result);
			Assert::IsFalse(success);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &startPoint, &rect, &result);
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

		TEST_METHOD(GetLinesIntersection)
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

		}

		TEST_METHOD(GetSegmentsCrossing)
		{
			sf::Vector2f A = sf::Vector2f(0.0f, 0.0f);
			sf::Vector2f B = sf::Vector2f(3.0f, 3.0f);
			sf::Vector2f C = sf::Vector2f(3.0f, -1.0f);
			sf::Vector2f D = sf::Vector2f(0.0f, 2.0f);
			sf::Vector2f result = sf::Vector2f();

			Assert::IsTrue(utilites::GetSegmentsCrossing(&A, &B, &C, &D, &result));
			Assert::AreEqual(1.0f, result.x);
			Assert::AreEqual(1.0f, result.y);

			A = sf::Vector2f(1.0f, 1.0f);
			Assert::IsTrue(utilites::GetSegmentsCrossing(&A, &B, &C, &D, &result));
			Assert::AreEqual(1.0f, result.x);
			Assert::AreEqual(1.0f, result.y);

			A = sf::Vector2f(1.01f, 1.01f);
			Assert::IsFalse(utilites::GetSegmentsCrossing(&A, &B, &C, &D, &result));
			
		}
	};
}
