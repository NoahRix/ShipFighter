
Engine::Engine()
{
	srand(time(NULL));
	font.loadFromFile("Fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(25);
	text.setFillColor(sf::Color::White);
	text.setPosition(10, SCREEN_HEIGHT - 40);
	//Image
	image.loadFromFile(("Sprites/wall.png"));
	texture.loadFromImage(image);
}

void Engine::getFrameRate(sf::RenderWindow & window)
{
	timer = clock.getElapsedTime();
	text.setString("FPS: " + to_string(1.0f / timer.asSeconds()));
	window.draw(text);
	clock.restart().asSeconds();
}
void Engine::EnemyPlayerBulletCollision(sf::RenderWindow & window, Player & player, Enemy & enemy, vector<Bullet>& playerBullets, vector<Bullet>& enemyBullets)
{
	if (playerBullets.size() > 0)
	{
		//Player bullets and enemy collison
		for (int i = 0; i < playerBullets.size(); i++)
		{
			if (playerBullets.size() > 0 && (playerBullets[i].getBounds().intersects(enemy.getBounds())))
			{
				player.incrementPlayerKillCount();
				enemyRandX = rand() % SCREEN_WIDTH;
				enemyRandY = 950;
				enemy.setNewLocation(enemyRandX, enemyRandY);
				cout << "Enemy Killed at: " << enemy.getEnemyX() << ", " << enemy.getEnemyY() << endl;
				if (playerBullets.size() > 0)
					playerBullets.erase(playerBullets.begin() + i);
			}
		}
		for (int i = 0; i < playerBullets.size(); i++)
		{
			playerBullets[i].drawBullet(window);
			if (playerBullets[i].getBulletX() > SCREEN_WIDTH || playerBullets[i].getBulletX() < 0 || playerBullets[i].getBulletY() > SCREEN_HEIGHT || playerBullets[i].getBulletY() < 0)
				if (playerBullets.size() > 0)
					playerBullets.erase(playerBullets.begin() + i);
		}
	}
	if (enemyBullets.size() > 0)
	{
		for (int i = 0; i < enemyBullets.size(); i++)
		{
			if (enemyBullets.size() > 0 && (enemyBullets[i].getBounds().intersects(player.getBounds())))
			{
				enemy.incrementEnemyKillCount();
				playerRandX = rand() % SCREEN_WIDTH;
				playerRandY = 50;
				player.setNewLocation(playerRandX, playerRandY);
				cout << "Player Killed at: " << player.getPlayerX() << ", " << player.getPlayerY() << endl;
				if (enemyBullets.size() > 0)
					enemyBullets.erase(enemyBullets.begin() + i);
			}
		}
		for (int i = 0; i < enemyBullets.size(); i++)
		{
			enemyBullets[i].drawBullet(window);
			if (enemyBullets[i].getBulletX() > SCREEN_WIDTH || enemyBullets[i].getBulletX() < 0 || enemyBullets[i].getBulletY() > SCREEN_HEIGHT || enemyBullets[i].getBulletY() < 0)
				if (enemyBullets.size())
					enemyBullets.erase(enemyBullets.begin() + i);
		}
	}
}

void Engine::playerWallColison(Player & player, vector<vector<Wall>>& walls)
{
	for (int i = 0; i < walls.size(); i++)
	{
		for (int j = 0; j < walls[i].size(); j++)
		{
			if (player.getBounds().intersects(walls[i][j].getBounds()))
			{
				if (player.getPlayerY() + player.getBounds().height / 2 > walls[i][j].getPostion().y && player.getPlayerY() < walls[i][j].getPostion().y + walls[i][j].getSize())
				{
					player.pauseSpeed();
					player.setNewLocation(player.getPlayerX(), player.getPlayerY() - player.getUniSpeed());
				}
				else
				{
					player.pauseSpeed();
					player.setNewLocation(player.getPlayerX(), player.getPlayerY() + player.getUniSpeed());
				}
				if (player.getPlayerX() + player.getBounds().width / 2 > walls[i][j].getPostion().x && player.getPlayerX() < walls[i][j].getPostion().x + walls[i][j].getSize())
				{
					player.pauseSpeed();
					player.setNewLocation(player.getPlayerX() - player.getUniSpeed(), player.getPlayerY());
				}
				else
				{
					player.pauseSpeed();
					player.setNewLocation(player.getPlayerX() + player.getUniSpeed(), player.getPlayerY());
				}
			}
		}
	}
}

void Engine::bulletWallCollison(vector<Bullet>& bullets, vector<vector<Wall>>& walls)
{
	int clearCount = 0;
	if (bullets.size() > 0)
	{
		for (int j = 0; j < walls.size(); j++)
		{
			for (int k = 0; k < walls[j].size(); k++)
			{
				for (int i = 0; i < bullets.size(); i++)
				{
					if (bullets[i].getBounds().intersects(walls[j][k].getBounds()) && walls[j][k].getIsCollidable() == true)
					{
						clearCount++;
						bulletCount++;
						bullets.erase(bullets.begin() + i);
						walls[j][k].setClear();
					}
				}
			}
		}
	}
	//cout << "clearCount = " << clearCount << endl;
	while (clearCount != 0)
	{	
		for (int j = 0; j < walls.size(); j++)
		{
			for (int k = 0; k < walls[j].size(); k++)
			{
				if (walls[j][k].getIsCollidable() == false)
				{
					walls[j].erase(walls[j].begin() + k);
					clearCount--;
					if (walls[j].empty())
					{
						cout << "Deleting row " << j + 1 << endl;
						cout << walls.size() << endl;
						walls.erase(walls.begin() + j);
					}
				}
			}
		}
	}
}

void Engine::render(sf::Clock & playerClock, sf::Clock & enemyClock, sf::RenderWindow & window, Player & player, Enemy & enemy, vector<Bullet>& playerBullets, vector<Bullet>& enemyBullets, vector<vector<Wall>>& walls, Crosshair & crosshair, sf::Vector2i & mCoord)
{
	
	playerShot = playerClock.getElapsedTime();
	playerReload = sf::milliseconds(10);
	enemyShot = enemyClock.getElapsedTime();
	enemyReload = sf::milliseconds(1000);

	window.clear();
	getFrameRate(window);
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && playerShot >= playerReload)
	{
		bulletCount++;
		pb.setBulletColor(sf::Color::Cyan);
		playerBullets.push_back(pb);
		playerBullets.back().setBulletNo(bulletCount);
		playerBullets.back().buildBullet(window, player.getPlayerX(), player.getPlayerY(), mCoord.x, mCoord.y);
		playerClock.restart();
	}
	if (enemyShot >= enemyReload)
	{
		eb.setBulletColor(sf::Color::Magenta);
		enemyBullets.push_back(eb);
		enemyBullets.back().buildBullet(window, enemy.getEnemyX(), enemy.getEnemyY(), player.getPlayerX(), player.getPlayerY());
		enemyClock.restart();
	}

	playerShot = playerClock.getElapsedTime();
	if (walls.size() == 0)
	{
		int i = 0;
		Wall w;
		//w.setImage(texture);
		cout << "setting image for wall texture" << endl;
		cout << "making walls" << endl;
		while (i < wallRow)
		{
			int j = 0;
			vector<Wall> wall;
			while (j < wallCol)
			{
				wall.push_back(w);
				wall[j].setPostion(j * wall[j].getSize(), wall[j].getSize() * (i + 10));
				wall[j].setWallNo((i + 1) * (j + 1));
				j++;
			}
			walls.push_back(wall);
			i++;
		}
		cout << "Generated " << wallRow * wallCol << " walls in " << playerClock.getElapsedTime().asMilliseconds() / 1000.2f << " seconds." << endl;
		playerClock.restart();
	}

	if (walls.size() > 0)
	{
		int i = 0;
		while (i < walls.size())
		{
			int j = 0;
			while (j < walls[i].size())
			{
				walls[i][j].drawWall(window);
				j++;
			}
			i++;
		}
	}

	//Player and enemy bullet collision
	EnemyPlayerBulletCollision(window, player, enemy, playerBullets, enemyBullets);

	//Player and Wall collion
	playerWallColison(player, walls);

	//wall and bullet collision
	bulletWallCollison(playerBullets, walls);
	bulletWallCollison(enemyBullets, walls);

	//Drawables
	crosshair.drawCrosshair(window);
	player.rotate(window, player);
	enemy.rotate(player);
	enemy.drawEnemy(window);
	player.drawPlayer(window);
	window.display();
}
