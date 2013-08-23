#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief The Player Class
 */
class Player
{
public:
    Player();
    void onSet();
    void display(sf::RenderWindow &target);
    void playerControls();

 sf::Sprite playerSprite;

private:
    int health;


    sf::Texture playerTexture;


};

#endif // GAME_PLAYER_HPP
