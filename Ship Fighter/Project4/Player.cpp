
Player::Player()
{
	srand(time(NULL));
	playerRandX = rand() % SCREEN_WIDTH;
	playerRandY = rand() % SCREEN_HEIGHT;
	player.setPointCount(3);
	player.setPoint(0, sf::Vector2f(20, 0));
	player.setPoint(1, sf::Vector2f(0, 40));
	player.setPoint(2, sf::Vector2f(40, 40));
	player.setFillColor(sf::Color::Green);
	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
	//Text
	font.loadFromFile("Fonts/arial.ttf");
	playerKillCount.setFont(font);
	playerKillCount.setCharacterSize(25);
	playerKillCount.setString("Player kill count: " + to_string(playerKills));
	playerKillCount.setFillColor(sf::Color::White);
	playerKillCount.setPosition(50, 10);
}

void Player::drawPlayer(sf::RenderWindow & window)
{
	playerX = playerX + speedX;
	playerY = playerY + speedY;
	player.setPosition(playerX, playerY);
	window.draw(player);
	window.draw(playerKillCount);
}

float Player::getPlayerX()
{
	return playerX;
}

float Player::getPlayerY()
{
	return playerY;
}

void Player::setNewLocation(int x, int y)
{
	playerX = x;
	playerY = y;
	player.setPosition(x, y);
}

void Player::pauseSpeed()
{
	notMoving = true;
	speedX = 0;
	speedY = 0;
}

void Player::lowUniSpeed()
{
	uniSpeed = sqrt(uniSpeed);
}

void Player::highUniSpeed()
{
	uniSpeed = pow(uniSpeed, 2);
}

void Player::moveUp()
{
	speedY = -uniSpeed;
}

void Player::moveDown()
{
	speedY = uniSpeed;
}

void Player::moveRight()
{
	speedX = uniSpeed;
}

void Player::moveLeft()
{
	speedX = -uniSpeed;
}

void Player::incrementPlayerKillCount()
{
	playerKills++;
	playerKillCount.setString("Player kill count: " + to_string(playerKills));
}

void Player::rotate(sf::RenderWindow & window, Player & c)
{
	sf::Vector2i mCoord = sf::Mouse::getPosition(window);
	float radToDeg = 57.2958;
	float angle = atan(((c.getPlayerX() - mCoord.x) / SCREEN_WIDTH) / ((c.getPlayerY() - mCoord.y) / SCREEN_HEIGHT));
	if (mCoord.y < c.getPlayerY())
	{
		player.setRotation(-angle * radToDeg);
	}
	if (mCoord.y > c.getPlayerY())
	{
		player.setRotation(-angle * radToDeg + 180);
	}
	if (mCoord.y == c.getPlayerY())
	{
		if (mCoord.x < c.getPlayerX())
			player.setRotation(270);
		if (mCoord.x > c.getPlayerX())
			player.setRotation(90);
		if (mCoord.x == c.getPlayerX())
		{
			player.setRotation(90);
		}
	}
}

sf::FloatRect Player::getBounds()
{
	return player.getGlobalBounds();
}

float Player::getUniSpeed()
{
	return uniSpeed;
}

void Player::logMovement(bool isColliding)
{
	if (isColliding == true)
	{
		timer = clock.getElapsedTime();
		reset = sf::milliseconds(30);
		if (timer >= reset)
		{
			for (int j = 0; j < 4; j++)
				clock.restart();
		}
		listTimer = listClock.getElapsedTime();
		if (listTimer >= sf::milliseconds(15))
		{
			backtrack[iter] = player.getPosition();
			iter++;
			if (iter > 3)
			{
				iter = 0;
				if (backtrack[0].x - backtrack[3].x > 0)
				{
					cout << "Moving Left" << endl;
					movingLeft = true;
				}
				else
					movingLeft = false;
				if (backtrack[0].x - backtrack[3].x < 0)
				{
					cout << "Moving Right" << endl;
					movingRight = true;
				}
				else
					movingRight = false;
				if (backtrack[0].y - backtrack[3].y < 0)
				{
					cout << "Moving Down" << endl;
					movingDown = true;
				}
				else
					movingDown == false;
				if (backtrack[0].y - backtrack[3].y > 0)
				{
					cout << "Moving Up" << endl;
					movingUp = true;
				}
				else
					movingUp = false;
				backtrack[0] = sf::Vector2f(0, 0);
				backtrack[1] = sf::Vector2f(0, 0);
			}
			listClock.restart();
		}
	}
}

sf::Vector2f Player::getBacktracked(int num)
{
	return backtrack[num];
}

void Player::setAbleToBackTrack(bool _bool)
{
	ableToBackTrack = _bool;
}

bool Player::isMovingUp()
{
	return movingUp;
}

bool Player::isMovingDown()
{
	return movingDown;
}

bool Player::isMovingRight()
{
	return movingRight;
}

bool Player::isMovingLeft()
{
	return movingLeft;
}

void Player::setLastValidPosition(sf::Vector2f pos)
{
	lastValidPosition = pos;
}

sf::Vector2f Player::getLastValidPosition()
{
	return lastValidPosition;
}
