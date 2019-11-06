#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;
static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = 1000;
#include "Player.h"
#include "Enemy.h"
#include "Wall.h"
#include "Bullet.h"
#include "Crosshair.h"
#include "Engine.h"

int main()
{
	Engine e;											//Render engine for all objects.
	Player player;										//Main player.
	Enemy enemy;										//Main enemy.
	Crosshair cr;										//Crosshair for player aim.
	vector<Bullet> *playerBullets = new vector<Bullet>;	//Default bullets as main player weapon.
	vector<Bullet> *enemyBullets = new vector<Bullet>;	//Default bullets as main enemy weapon.			
	vector<vector<Wall>> wall;							//Wall
	vector<Enemy> en;									//Circle shape as enemy.
	sf::Clock playerClock;								//Clock for player's bullets
	sf::Clock enemyClock;								//Clock for enemy's bullets
	bool wait = false;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Ship Fighter");
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setMouseCursorVisible(false);
	sf::Event event;
	while (window.isOpen())
	{
		sf::Vector2i mCoord = sf::Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				player.pauseSpeed();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					player.moveUp();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					player.moveUp();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					player.moveDown();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					player.moveLeft();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					player.moveRight();
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				wait = true;
		}
		if (wait == true);
			e.render(playerClock, enemyClock, window, player, enemy, *playerBullets, *enemyBullets, wall, cr, mCoord); //Member to render.
	}
	return 0;
}

 