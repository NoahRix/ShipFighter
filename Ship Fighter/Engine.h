#ifndef ENGINE_H_
#define ENGINE_H_
class Engine
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::Text text;
	sf::Font font;
	sf::Clock clock;
	sf::Time playerShot;
	sf::Time enemyShot;
	sf::Time playerReload;
	sf::Time enemyReload;
	sf::Time timer;
	Bullet pb;
	Bullet eb;
	int wallamount = 0;
	int bulletCount = 0;
	int wallCol = 50;
	int wallRow = 16;
	float playerRandX;
	float playerRandY;
	float enemyRandX;
	float enemyRandY;
	bool noWalls;
	bool isColliding = false;
public:
	Engine();
	void getFrameRate(sf::RenderWindow &window);
	void EnemyPlayerBulletCollision(sf::RenderWindow &window, Player &player, Enemy &enemy, vector<Bullet> &playerBullets, vector<Bullet> &enemyBullets);
	void playerWallColison(Player &player, vector<vector<Wall>> &walls);
	void bulletWallCollison(vector<Bullet> &bullets, vector<vector<Wall>> &walls);
	void render(sf::Clock &playerClock, sf::Clock &enemyClock, sf::RenderWindow &window, Player &player, Enemy &enemy, vector<Bullet> &playerBullets, vector<Bullet> &enemyBullets, vector<vector<Wall>> &walls, Crosshair &crosshair, sf::Vector2i &mCoord);
};
#include "Engine.cpp"
#endif /*ENGINE_H_*/