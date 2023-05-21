#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
	int mv = 5;

	RenderWindow window(VideoMode(800, 600), "YOUSSEF");
	window.setFramerateLimit(30);

	Texture l;
	l.loadFromFile("walker2.png");
	int x = 0;
	int y = 0;

	Texture BK;
	BK.loadFromFile("background.png");

	Texture coin;
	coin.loadFromFile("coin.png");

	Sprite coin1;
	coin1.setTexture(coin);
	coin1.setScale(0.5, 0.5);
	coin1.setTextureRect(IntRect(x * 116, y * 147, 116, 147));
	coin1.setPosition(300, 200);

	Sprite pl1;
	pl1.setTexture(l);
	pl1.setScale(0.5, 0.5);
	pl1.setTextureRect(IntRect(x * 116, y * 147, 116, 147));
	pl1.setPosition(300, 200);

	Sprite BK1;
	BK1.setTexture(BK);
	BK1.setScale(1.8, 1.3);



	/*
		Sprite pl2;
		pl2.setTexture(l);
		pl2.setScale(0.2, 0.2);
		pl2.setPosition(400, 300);
		*/
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Mouse::isButtonPressed(Mouse::Right))
		{
			Vector2i mouseposition = Mouse::getPosition(window);
			pl1.setPosition(mouseposition.x, mouseposition.y);

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D) && pl1.getPosition().x < 690)
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				pl1.move(20, 0);
			}
			pl1.move(mv, 0);
			x++;
			pl1.setTextureRect(IntRect(x * 116, 2 * 147, 116, 147));
			if (x == 3)
			{
				x = 0;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::A) && pl1.getPosition().x > 0)
		{

			if (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				pl1.move(-20, 0);
			}

			pl1.move(-mv, 0);
			x++;
			pl1.setTextureRect(IntRect(x * 116, 3 * 147, 116, 147));
			if (x == 3)
			{
				x = 0;
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::W) && pl1.getPosition().y > 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				pl1.move(0, -20);
			}

			pl1.move(0, -mv);
			x++;
			pl1.setTextureRect(IntRect(x * 116, 1 * 147, 116, 147));
			if (x == 3)
			{
				x = 0;
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S) && pl1.getPosition().y < 460)
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Space))
			{
				pl1.move(0, 20);
			}

			pl1.move(0, mv);
			x++;
			pl1.setTextureRect(IntRect(x * 116, 0 * 147, 116, 147));
			if (x == 3)
			{
				x = 0;
			}
		}


		if (pl1.getGlobalBounds().intersects(BK1.getGlobalBounds()))
		{
		}

		/*	if (pl1.getGlobalBounds().intersects(pl2.getGlobalBounds()))
			{
				pl2.move(0, 2);
			}
			*/
		window.clear();
		window.draw(BK1);
		window.draw(pl1);
		window.draw(coin1);
		//	window.draw(pl2);
		window.display();

	}

}