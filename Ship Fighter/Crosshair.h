#ifndef CROSSHAIR_H_
#define CROSSHAIR_H_
class Crosshair
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite crosshair;
	sf::Clock clock;
	sf::Time timeStart;
	sf::Time timeEnd;
	float x = 0;
	float y = 0;
public:
	Crosshair();
	void drawCrosshair(sf::RenderWindow &window);
};
#include "Crosshair.cpp"
#endif /*CROSSHAIR_H_*/