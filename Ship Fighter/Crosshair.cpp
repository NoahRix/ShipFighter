Crosshair::Crosshair()
{
	image.loadFromFile("Sprites/Crosshair_1.png");
	image.createMaskFromColor(sf::Color::White);
	texture.loadFromImage(image);
	crosshair.setTexture(texture);
	crosshair.setOrigin(crosshair.getGlobalBounds().width / 2, crosshair.getGlobalBounds().height / 2);
	crosshair.setPosition(x, y);
}

void Crosshair::drawCrosshair(sf::RenderWindow & window)
{
	sf::Vector2i mCoord = sf::Mouse::getPosition(window);
	crosshair.setPosition(mCoord.x, mCoord.y);
	crosshair.rotate(10);
	window.draw(crosshair);
}