// SFML_SimplePlatformerEngine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "MagicGrid.h"


int main()
{
	std::cout << "Hello World!\n";

	

	//unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(500, 250, 30.0f);

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(60);
	//window.setSize(sf::Vector2u(window.getSize().x, (uint32_t)(window.getSize().x * 9 / 16)));

	unique_ptr<MagicGrid> grid = make_unique<MagicGrid>(10, 10, 10.0f);

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
						//window.setSize(sf::Vector2u(event.size.width, (uint32_t)(event.size.width * 9 / 16)));
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
		window.draw(*grid.get());
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
