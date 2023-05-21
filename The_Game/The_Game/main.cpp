#include <iostream>
#include <vector>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
using namespace sf;
using namespace std;

Vector2f velocity(0, 0);

int level1tiles[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,46,47,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,45,46,47,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,50,51,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,49,50,51,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,46,47,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,50,51,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,44,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,46,47,48,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,50,51,52,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,46,47,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,45,46,47,48,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,50,51,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,49,50,51,52,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,42,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,10,42,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10,10,10,42,10,10,-1,-1,-1,-1,-1,53,16,17,18,19,
				   -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,20,21,22,23,24,
				   -1,-1,-1,-1,-1,-1,0,1,-1,-1,2,3,-1,-1,-1,-1,-1,13,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,5,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,26,27,28,29,
				   -1,-1,-1,-1,-1,-1,2,3,-1,-1,2,3,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,-1,-1,-1,-1,-1,-1,-1,30,31,32,33,34,
				   -1,-1,11,12,-1,-1,2,3,-1,-1,2,3,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,10,10,10,10,10,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,3,-1,-1,-1,-1,-1,-1,-1,35,36,37,38,39,
				   40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,-1,-1,-1,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,40,
				   41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,40,40,40,-1,-1,-1,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41,41 };
RectangleShape m[2800];
Texture Tiles[60];
void setTile() {
	Tiles[0].loadFromFile("pipes2hl.png");
	Tiles[1].loadFromFile("pipes2hr.png");
	Tiles[2].loadFromFile("pipes2bl.png");
	Tiles[3].loadFromFile("pipes2br.png");
	Tiles[4].loadFromFile("pipes3hl.png");
	Tiles[5].loadFromFile("pipes3hm.png");
	Tiles[6].loadFromFile("pipes3hr.png");
	Tiles[7].loadFromFile("pipes3bl.png");
	Tiles[8].loadFromFile("pipes3bm.png");
	Tiles[9].loadFromFile("pipes3br.png");
	Tiles[10].loadFromFile("brick.png");
	Tiles[11].loadFromFile("red1.png");
	Tiles[12].loadFromFile("red2.png");
	Tiles[13].loadFromFile("tree1.png");
	Tiles[14].loadFromFile("tree2.png");
	Tiles[15].loadFromFile("tree3.png");
	Tiles[53].loadFromFile("ca1.png");
	Tiles[16].loadFromFile("ca2.png");
	Tiles[17].loadFromFile("ca3.png");
	Tiles[18].loadFromFile("ca4.png");
	Tiles[19].loadFromFile("ca5.png");
	Tiles[20].loadFromFile("ca6.png");
	Tiles[21].loadFromFile("ca7.png");
	Tiles[22].loadFromFile("ca8.png");
	Tiles[23].loadFromFile("ca9.png");
	Tiles[24].loadFromFile("ca10.png");
	Tiles[25].loadFromFile("ca11.png");
	Tiles[26].loadFromFile("ca12.png");
	Tiles[27].loadFromFile("ca13.png");
	Tiles[28].loadFromFile("ca14.png");
	Tiles[29].loadFromFile("ca15.png");
	Tiles[30].loadFromFile("ca16.png");
	Tiles[31].loadFromFile("ca17.png");
	Tiles[32].loadFromFile("ca18.png");
	Tiles[33].loadFromFile("ca19.png");
	Tiles[34].loadFromFile("ca20.png");
	Tiles[35].loadFromFile("ca21.png");
	Tiles[36].loadFromFile("ca22.png");
	Tiles[37].loadFromFile("ca23.png");
	Tiles[38].loadFromFile("ca24.png");
	Tiles[39].loadFromFile("ca25.png");
	Tiles[40].loadFromFile("ground1.png");
	Tiles[41].loadFromFile("ground 2.png");
	Tiles[42].loadFromFile("quest.png");
	Tiles[43].loadFromFile("sky1.png");
	Tiles[44].loadFromFile("sky2.png");
	Tiles[45].loadFromFile("sky3.png");
	Tiles[46].loadFromFile("sky4.png");
	Tiles[47].loadFromFile("sky5.png");
	Tiles[48].loadFromFile("sky6.png");
	Tiles[49].loadFromFile("sky7.png");
	Tiles[50].loadFromFile("sky8.png");
	Tiles[51].loadFromFile("sky9.png");
	Tiles[52].loadFromFile("sky10.png");
}
void draw1()
{
	for (int i = 0; i < 2800; ++i)
	{
		m[i].setSize(Vector2f(16, 16));
		if (level1tiles[i] == -1) {
			m[i].setFillColor(Color(162, 216, 225));
		}
		else {
			m[i].setTexture(&Tiles[level1tiles[i]]);
		}
		m[i].setPosition((i % 70) * 16, (i / 70) * 16);
	}
}
int main()
{
	Clock clock;

	//double velocity = 0;
	int x = 0, count_menu = 0;
	bool grounded = false, goomba_collison = false;
	int coin_animation_indicator = 0, y = 0, score = 0;
	RenderWindow window(VideoMode(1300, 700), "MARIO");
	window.setFramerateLimit(150);
	RectangleShape r(Vector2f(20, 200));
	r.setPosition(740, 390);
	/*
	//right side
	RectangleShape r(Vector2f(5, 80));
	r.setPosition(175, 422);
	//left side
	RectangleShape l(Vector2f(5, 80));
	l.setPosition(120, 422);
	*/


	RectangleShape high_ground(Vector2f(200, 10));
	high_ground.setPosition(600, 600);

	RectangleShape ground(Vector2f(2000, 20));
	ground.setPosition(400, 500);

	//death goomba
	Texture goombad;
	goombad.loadFromFile("goomba d.png");
	Sprite goombadd;

	//goomba
	Texture goomba;
	goomba.loadFromFile("goomba w.png");

	Texture mario;  //el sora el soghyra  (2)
	mario.loadFromFile("mario sp.png");
	Sprite mario1;
	mario1.setTexture(mario);
	mario1.setTextureRect(IntRect(x * 60, 0 * 97, 60, 97)); // w  h
	mario1.setPosition(0, 100);
	mario1.setScale(0.5, 0.5);
	//menu
	Texture menu;
	menu.loadFromFile("menu.png");
	Sprite menu1;
	menu1.setTexture(menu);
	menu1.setPosition(0, 0);
	menu1.setScale(0.9, 0.7);
	Texture coinTextute;
	coinTextute.loadFromFile("coins.png");

	Sprite coins[10];
	for (size_t i = 0; i < 10; i++) {

		coins[i].setTexture(coinTextute);
		coins[i].setPosition(70 + (i * 70), 560);
		coins[i].setTextureRect(IntRect(1, 1, 100, 100));
		coins[i].setScale(0.1, 0.1);

	}
	Font font;
	font.loadFromFile("mario font.ttf");
	Text text;
	text.setFont(font);
	text.setString("Score: " + std::to_string(score));
	text.setFillColor(Color::White);
	text.setPosition(0, 0);
	text.setCharacterSize(32);
	//goomba draw
	Sprite goombas[8];
	for (size_t i = 0; i < 8; i++)
	{

		goombas[i].setTexture(goomba);
		goombas[i].setTextureRect(IntRect(x * 16, 0 * 16, 16, 16));
		goombas[i].setScale(1.5, 1.5);
		goombas[i].setPosition(90 + (i * 100), 585);
	}
	//death goomba draw
	Sprite goombab[8];
	for (size_t i = 0; i < 8; i++)
	{

		goombab[i].setTexture(goombad);
		goombab[i].setScale(0, 0);
		goombas[i].setPosition(90 + (i * 100), 585);
	}
	//sound of coins
	sf::SoundBuffer buffer;
	buffer.loadFromFile("coins.ogg");
	sf::Sound sound;
	sound.setBuffer(buffer);
	// sound of game
	Music music;
	music.openFromFile("Super Mario Bros. medley.ogg");
	music.play();


	setTile();
	draw1();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Vector2i mousepos = Mouse::getPosition(window);
			if (mousepos.x > 450 && mousepos.x < 600 && mousepos.y>120 && mousepos.y < 180)
			{
				menu1.setScale(0, 0);

			}
			if (mousepos.x > 450 && mousepos.x < 600 && mousepos.y>230 && mousepos.y < 280)
			{
				window.close();
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::Key::Right) && mario1.getPosition().x < 950)
		{
			mario1.setScale(0.5, 0.5);
			x++;
			x %= 4;
			mario1.setTextureRect(IntRect(x * 60, 0 * 97, 60, 97));
			mario1.move(3, 0);
			mario1.setOrigin(0, 0);



		}

		coin_animation_indicator++;
		coin_animation_indicator = coin_animation_indicator % 6;

		if (Keyboard::isKeyPressed(Keyboard::Key::Left) && mario1.getPosition().x > 0)
		{
			mario1.setScale(-0.5, 0.5);
			mario1.move(-3, 0);
			x++;
			x %= 4;
			mario1.setTextureRect(IntRect(x * 60, 0 * 97, 60, 97));

			mario1.setOrigin(mario1.getLocalBounds().width, 0);

		}
		//|| ((high_ground.getGlobalBounds().intersects(mario1.getGlobalBounds())))
		if (ground.getGlobalBounds().intersects(mario1.getGlobalBounds()))
		{

			grounded = true;

			velocity.y = 0;
			if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			{
				velocity.y = 7;

			}
		}
		else
		{
			grounded = false;
			velocity.y -= 0.1;

		}
		mario1.move(0, -velocity.y);

		/*
		//pipes collison
		for (size_t i = 0; i < 8; i++)
		{
			if (mario1.getGlobalBounds().intersects(r.getGlobalBounds()))
			{

				mario1.move(-2, 0);
			}
		}
		*/
		//collison for coins
		for (size_t i = 0; i < 10; i++) {
			if (mario1.getGlobalBounds().intersects(coins[i].getGlobalBounds())) {
				coins[i].setScale(0, 0);
				score++;
				text.setString("Score: " + std::to_string(score));
				sound.play();
				music.pause();
			}
		}
		//goombas move
		/*for (size_t i = 0; i < 8; i++)
		{
			goombas[i].move(-0.5, 0);
			goombab[i].move(-0.5, 0);
		}*/
		//collison for goomba
		for (size_t i = 0; i < 8; i++)
		{
			if ((mario1.getGlobalBounds().intersects(goombas[i].getGlobalBounds())) && (velocity.y < 0))
			{

				goombas[i].setScale(0, 0);
				goombab[i].setScale(2, 2);

			}
			else if ((mario1.getGlobalBounds().intersects(goombas[i].getGlobalBounds())) && (grounded = true))
			{
				mario1.setScale(0, 0);
			}
		}





		window.clear();
		for (int i = 0; i < 2800; ++i) {
			window.draw(m[i]);
		}
		window.draw(mario1);
		for (size_t i = 0; i < 8; i++)
		{
			window.draw(goombas[i]);
		}
		for (size_t i = 0; i < 8; i++)
		{
			window.draw(goombab[i]);
		}
		for (size_t i = 0; i < 10; i++) {
			coins[i].setTextureRect(sf::IntRect(coin_animation_indicator * 190, 0, 190, 190));
			window.draw(coins[i]);
		}

		//window.draw(r);
		//window.draw(high_ground);
		window.draw(menu1);
		window.draw(text);
		window.display();
	}

	return 0;
}