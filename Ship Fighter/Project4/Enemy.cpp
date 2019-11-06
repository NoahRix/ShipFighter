
Enemy::Enemy()
{
	srand(time(NULL));
	enemyRandX = rand() % SCREEN_WIDTH;
	enemyRandY = 950;
	enemy.setPointCount(3);
	enemy.setPoint(0, sf::Vector2f(20, 0));
	enemy.setPoint(1, sf::Vector2f(0, 40));
	enemy.setPoint(2, sf::Vector2f(40, 40));
	enemy.setFillColor(sf::Color::Red);
	enemy.setOrigin(enemy.getGlobalBounds().width / 2, enemy.getGlobalBounds().height / 2);
	enemyX = enemyRandX;
	enemyY = enemyRandY;
	enemy.setPosition(enemyX, enemyY);
	//Text
	font.loadFromFile("Fonts/arial.ttf");
	enemyKillCount.setFont(font);
	enemyKillCount.setCharacterSize(25);
	enemyKillCount.setString("Enemy kill count: " + to_string(enemyKills));
	enemyKillCount.setFillColor(sf::Color::White);
	enemyKillCount.setPosition(700, 10);
}

void Enemy::drawEnemy(sf::RenderWindow & window)
{
	window.draw(enemyKillCount);
	window.draw(enemy);
}

void Enemy::setNewLocation(int x, int y)
{
	enemyX = x;
	enemyY = y;
	enemy.setPosition(x, y);
}

float Enemy::getEnemyX()
{
	return enemyX;
}

float Enemy::getEnemyY()
{
	return enemyY;
}

sf::FloatRect Enemy::getBounds()
{
	return enemy.getGlobalBounds();
}

void Enemy::incrementEnemyKillCount()
{
	enemyKills++;
	enemyKillCount.setString("Enemy kill count: " + to_string(enemyKills));
}

void Enemy::rotate(Player & p)
{
	float radToDeg = 57.2958;
	float angle = atan(((enemyX - p.getPlayerX()) / SCREEN_WIDTH) / ((enemyY - p.getPlayerY()) / SCREEN_HEIGHT));
	if (p.getPlayerY() < enemyY)
	{
		enemy.setRotation(-angle * radToDeg);
	}
	if (p.getPlayerY() > enemyY)
	{
		enemy.setRotation(-angle * radToDeg + 180);
	}
	if (p.getPlayerY() == enemyY)
	{
		if (p.getPlayerX() < enemyX)
			enemy.setRotation(270);
		if (p.getPlayerX() > enemyX)
			enemy.setRotation(90);
		if (p.getPlayerX() == enemyX)
		{
			enemy.setRotation(90);
		}
	}
}
