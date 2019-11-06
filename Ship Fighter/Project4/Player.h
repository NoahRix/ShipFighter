#ifndef PLAYER_H_
#define PLAYER_H_
class Player
{
private:
	sf::ConvexShape player;
	sf::Clock clock;
	sf::Clock listClock;
	sf::Time timer;
	sf::Time listTimer;
	sf::Time reset;
	sf::Text playerKillCount;
	sf::Font font;
	//sf::Sprite player;
	sf::Image image;
	sf::Texture texture;
	sf::Vector2f backtrack[4];
	sf::Vector2f lastValidPosition;
	int playerKills = 0;
	int iter = 0;
	float playerX = rand() % SCREEN_WIDTH;
	float playerY = 50;
	float speedX = 0;
	float speedY = 0;
	float uniSpeed = 5;
	float playerRandX;
	float playerRandY;
	bool notMoving;
	bool movingUp;
	bool movingDown;
	bool movingRight;
	bool movingLeft;
	bool ableToBackTrack = true;
public:
	Player();
	void drawPlayer(sf::RenderWindow& window);
	float getPlayerX();
	float getPlayerY();
	void setNewLocation(int x, int y);
	void pauseSpeed();
	void lowUniSpeed();
	void highUniSpeed();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void incrementPlayerKillCount();
	void rotate(sf::RenderWindow &window, Player &c);
	sf::FloatRect getBounds();
	float getUniSpeed();
	void logMovement(bool isColliding);
	sf::Vector2f getBacktracked(int num);
	void setAbleToBackTrack(bool _bool);
	bool isMovingUp();
	bool isMovingDown();
	bool isMovingRight();
	bool isMovingLeft();
	void setLastValidPosition(sf::Vector2f pos);
	sf::Vector2f getLastValidPosition();
	
};
#include "Player.cpp"
#endif /*PLAYER_H_*/