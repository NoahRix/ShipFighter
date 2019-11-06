
Bullet::Bullet()
{
	bullet.setPosition(bulletX, bulletY);
	bullet.setFillColor(sf::Color::Yellow);
	bullet.setRadius(radius);
	bullet.setOrigin(bullet.getGlobalBounds().width / 2, bullet.getGlobalBounds().height / 2);
	bullet.setOutlineColor(sf::Color::White);
	bullet.setOutlineThickness(outlineThickness);
}

void Bullet::drawBullet(sf::RenderWindow & window)
{
	float radToDeg = 57.2958;
	float bulletAngle = atan(((bulletStartX - bulletEndX) / SCREEN_WIDTH) / ((bulletStartY - bulletEndY) / SCREEN_HEIGHT));

	if (bulletEndY > bulletStartY)
	{
		bulletX = bulletX + sin(bulletAngle) * bulletSpeed;
		bulletY = bulletY + cos(bulletAngle) * bulletSpeed;
	}
	if (bulletEndY < bulletStartY)
	{
		bulletX = bulletX - sin(bulletAngle) * bulletSpeed;
		bulletY = bulletY - cos(bulletAngle) * bulletSpeed;
	}
	if (bulletEndY == bulletStartY)
	{
		if (bulletEndX < bulletStartX)
			bulletX = bulletX - bulletSpeed;
		if (bulletEndX > bulletStartX)
			bulletX = bulletX + bulletSpeed;
		if (bulletEndX == bulletStartX)
		{
			bulletX = bulletX + bulletSpeed;
		}
	}
	bullet.setPosition(bulletX + sin(bulletAngle), bulletY + cos(bulletAngle));
	window.draw(bullet);
}

float Bullet::getBulletX()
{
	return bulletX;
}

float Bullet::getBulletY()
{
	return bulletY;
}

sf::FloatRect Bullet::getBounds()
{
	return bullet.getGlobalBounds();
}

sf::Vector2f Bullet::getPosition()
{
	return bullet.getPosition();
}

void Bullet::buildBullet(sf::RenderWindow & window, float cx, float cy, float mx, float my)
{
	bulletStartX = cx;
	bulletStartY = cy;
	bulletEndX = mx;
	bulletEndY = my;
	bulletX = cx;
	bulletY = cy;
}

void Bullet::setBulletColor(sf::Color color)
{
	bullet.setOutlineColor(color);
	bullet.setFillColor(color);
}

int Bullet::getBulletNo()
{
	return bulletNo;
}

void Bullet::setBulletNo(int num)
{
	bulletNo = num;
}
