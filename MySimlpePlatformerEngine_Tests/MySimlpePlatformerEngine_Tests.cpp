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

	TEST_CLASS(MySimlpePlatformerEngineTests_utilites)
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
			Assert::AreEqual(true, success);
			Assert::AreEqual(result.x, result1.x);
			Assert::AreEqual(result.y, result1.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint2, &rect, &result);
			Assert::AreEqual(true, success);
			Assert::AreEqual(result.x, result2.x);
			Assert::AreEqual(result.y, result2.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint3, &rect, &result);
			Assert::AreEqual(true, success);
			Assert::AreEqual(result.x, result3.x);
			Assert::AreEqual(result.y, result3.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint4, &rect, &result);
			Assert::AreEqual(true, success);
			Assert::AreEqual(result.x, result4.x);
			Assert::AreEqual(result.y, result4.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint5, &rect, &result);
			Assert::AreEqual(true, success);
			Assert::AreEqual(result.x, result5.x);
			Assert::AreEqual(result.y, result5.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint6, &rect, &result);
			Assert::AreEqual(true, success);
			Assert::AreEqual(result.x, result6.x);
			Assert::AreEqual(result.y, result6.y);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint2, &endPoint6, &rect, &result);
			Assert::AreEqual(false, success);
			success = utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &startPoint, &rect, &result);
			Assert::AreEqual(false, success);
			//Assert::AreEqual(1, 1);
		}
	};
}
