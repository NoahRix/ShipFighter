
Wall::Wall()
{
	wall.setSize(sf::Vector2f(16, 16));
	wall.setFillColor(sf::Color(200, 200, 200));
	wall.setOutlineColor(sf::Color(80, 80, 80));
	wall.setOutlineThickness(2);
	wall.setPosition(wallX, wallY);
}

void Wall::setClear()
{
	wall.setFillColor(sf::Color::Transparent);
	wall.setOutlineColor(sf::Color::Transparent);
	isCollidable = false;
}

bool Wall::getIsCollidable()
{
	return isCollidable;
}

void Wall::setPostion(int x, int y)
{
	wall.setPosition(x, y);
}

void Wall::drawWall(sf::RenderWindow & window)
{
	window.draw(wall);
}

void Wall::setWallNo(int num)
{
	wallNo = num;
}

int Wall::getWallNo()
{
	return wallNo;
}

sf::Vector2f Wall::getPostion()
{
	return wall.getPosition();
}

float Wall::getSize()
{
	return wall.getGlobalBounds().width;
}

sf::FloatRect Wall::getBounds()
{
	return wall.getGlobalBounds();
}
