#ifndef BULLET_H_
#define BULLET_H_
class Bullet
{
private:
	sf::CircleShape bullet;
	float radius = 3;
	float outlineThickness = 1;
	float bulletX = 0;
	float bulletY = 0;
	float bulletStartX = 0;
	float bulletStartY = 0;
	float bulletEndX = 0;
	float bulletEndY = 0;
	float bulletSpeed = 15;
	float damage = 3;
	int bulletNo = 0;
public:
	Bullet();
	void drawBullet(sf::RenderWindow &window);
	float getBulletX();
	float getBulletY();
	sf::FloatRect getBounds();
	sf::Vector2f getPosition();
	void buildBullet(sf::RenderWindow &window, float cx, float cy, float mx, float my);
	void setBulletColor(sf::Color color);
	int getBulletNo();
	void setBulletNo(int num);
};
#include "Bullet.cpp"
#endif /*BULLET_H_*/