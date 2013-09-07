#include "Game/Player.hpp"

Player::Player()
{

    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);
    center = sf::Vector2f(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
}

void Player::update(Layer &mainLayer)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playerSprite.move(-1, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playerSprite.move(1, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        playerSprite.move(0, -1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        playerSprite.move(0, 1);

    int playerX, playerY, playerWidth, playerHeight, playerXmax, playerYmax;
    playerX = playerSprite.getPosition().x;
    playerY = playerSprite.getPosition().y;
    playerWidth = playerTexture.getSize().x;
    playerHeight = playerTexture.getSize().y;
    playerXmax = playerX + playerWidth;
    playerYmax = playerY + playerHeight;

    int layerX, layerY, layerWidth, layerHeight;
    layerX = mainLayer.getPosition().x;
    layerY = mainLayer.getPosition().y;
    layerWidth = mainLayer.getWidth();
    layerHeight = mainLayer.getHeight();

    int relX, relY, relXmax, relYmax;
    relX = playerX - layerX;
    relY = playerY - layerY;
    relXmax = playerXmax - layerX + GRID_SIZE;
    relYmax = playerYmax - layerY + GRID_SIZE;

    if (relX < 0) relX = 0;
    if (relY < 0) relY = 0;
    if (relXmax < 0) relXmax = 0;
    if (relYmax < 0) relYmax = 0;

    if (relX > layerWidth) relX = layerWidth;
    if (relY > layerHeight) relY = layerHeight;
    if (relXmax > layerWidth) relXmax = layerWidth;
    if (relYmax > layerHeight) relYmax = layerHeight;

    int xmin, ymin, xmax, ymax;
    xmin = relX / GRID_SIZE;
    ymin = relY / GRID_SIZE;
    xmax = relXmax / GRID_SIZE;
    ymax = relYmax / GRID_SIZE;

    botArea = sf::FloatRect(relX, relY+playerHeight/2, playerWidth, playerHeight / 2);
    leftArea = sf::FloatRect(relX, relY, playerWidth/2,playerHeight);
    rightArea = sf::FloatRect(relX+playerWidth/2, relY, playerWidth/2, playerHeight);
    topArea = sf::FloatRect(relX, relY, playerWidth, playerHeight/2);

    for (int i = xmin; i < xmax; i++)
    {
        for (int j = ymin; j < ymax; j++)
        {
            if (mainLayer(i, j))
            {
                if(hitTest(botArea,
                            sf::FloatRect(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE)))
                {
                    playerSprite.move(0,-1);
                }

                if(hitTest(leftArea,
                           sf::FloatRect(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE)))
                {
                    playerSprite.move(1,0);
                }

                if(hitTest(rightArea,
                           sf::FloatRect(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE)))
                {
                    playerSprite.move(-1,0);
                }
            }
        }
    }
}

void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);

    sf::RectangleShape bg(sf::Vector2f(playerTexture.getSize().x, playerTexture.getSize().y / 2));
    bg.setFillColor(sf::Color(255, 0, 0, 75));
    bg.move(playerSprite.getPosition().x, getCenter().y);
    target.draw(bg);

    sf::RectangleShape lg(sf::Vector2f(playerTexture.getSize().x/2, playerTexture.getSize().y));
    lg.setFillColor(sf::Color(255, 0, 255, 50));
    lg.move(playerSprite.getPosition().x, playerSprite.getPosition().y);
    target.draw(lg);

    sf::RectangleShape rg(sf::Vector2f(playerTexture.getSize().x/2, playerTexture.getSize().y));
    rg.setFillColor(sf::Color(0, 255, 255, 50));
    rg.move(playerSprite.getPosition().x+playerTexture.getSize().x/2, playerSprite.getPosition().y);
    target.draw(rg);
}

sf::Vector2f Player::getCenter()
{
    return playerSprite.getPosition() + center;
}
