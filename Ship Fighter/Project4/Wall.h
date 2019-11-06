#ifndef WALL_H_
#define WALL_H_
class Wall
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::RectangleShape wall;
	float wallX = 0;
	float wallY = 0;
	int wallNo;
	bool isCollidable = true;
public:
	Wall();
	void setClear();
	bool getIsCollidable();
	void setPostion(int x, int y);
	void drawWall(sf::RenderWindow &window);
	void setWallNo(int num);
	int getWallNo();
	sf::Vector2f getPostion();
	sf::FloatRect getBounds();
	float getSize();
};
#include "Wall.cpp"
#endif /*WALL_H_*/