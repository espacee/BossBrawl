#ifndef GUI_UI_HPP
#define GUI_UI_HPP

#include <SFML/Graphics.hpp>
#include "Entities/Player.hpp"

/**
 * @brief Game UI
 */
class UI
{
public:
    UI();

    void onInit();
    void display(sf::RenderWindow& window);
    void update(Player& player);



float playerhealth;

sf::Text healthtext;
sf::RectangleShape healthbarout;
sf::RectangleShape healthbarin;

};

#endif // GUI_UI_HPP
