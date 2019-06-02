// SFML_SimplePlatformerEngine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "MagicGrid.h"


int main()
{
	std::cout << "Hello World!\n";

	

	//unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(500, 250, 30.0f);

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(60);

	sf::View view = window.getView();
	//sf::FloatRect rect = sf::FloatRect(view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2, view.getSize().x, view.getSize().y);
	sf::FloatRect rect = sf::FloatRect(0.0f, 0.0f, 6.0f, 4.0f);
	sf::Vector2f startPoint = sf::Vector2f(3.0f, 1.0f);
	sf::Vector2f startPoint2 = sf::Vector2f(300.0f, 1.0f);
	sf::Vector2f endPoint1 = sf::Vector2f(1.0f, 1.0f);
	sf::Vector2f endPoint2 = sf::Vector2f(2.5f, 0.5f);
	sf::Vector2f endPoint3 = sf::Vector2f(4.0f, 0.5f);
	sf::Vector2f endPoint4 = sf::Vector2f(1.0f, 3.0f);
	sf::Vector2f endPoint5 = sf::Vector2f(4.5f, 1.5f);
	sf::Vector2f endPoint6 = sf::Vector2f(3.0f, 2.0f);
	sf::Vector2f result = sf::Vector2f();
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint1, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint2, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint3, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint4, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint5, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &endPoint6, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint2, &endPoint6, &rect, &result);
	utilites::GetRayAndViewBorderCrossingPoint(&startPoint, &startPoint, &rect, &result);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					{
						window.close();
						break;
					}
				case sf::Event::Resized:
					{
						
						break;
					}
				default:
					{
						break;
					}
			}
			/*if (event.type == sf::Event::Closed)
				window.close();*/
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
