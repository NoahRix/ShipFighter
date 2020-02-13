#ifndef ENEMY_H_
#define ENEMY_H_
class Enemy
{
private:
	sf::Text enemyKillCount;
	sf::Font font;
	sf::ConvexShape enemy;
	int enemyKills = 0;
	float radius = 10;
	float outlineThickness = 1;
	float enemyX = rand() % SCREEN_WIDTH;
	float enemyY = 950;
	float speedX = 0;
	float speedY = 0;
	float enemyRandX;
	float enemyRandY;
public:
	Enemy();
	void drawEnemy(sf::RenderWindow &window);
	void setNewLocation(int x, int y);
	float getEnemyX();
	float getEnemyY();
	sf::FloatRect getBounds();
	void incrementEnemyKillCount();
	void rotate(Player &p);
};
#include "Enemy.cpp"
#endif /*ENEMY_H_*/
