#include "Gui/UI.hpp"
#include "Core/graphics.hpp"
#include "Core/graphics.hpp"

UI::UI()
{
    onInit();

}
void UI::onInit()
{


    healthbarout.setFillColor(sf::Color::Black);
    healthbarin.setFillColor(sf::Color::Red);

    healthbarout.setSize(sf::Vector2f(100,20));
    healthbarin.setSize(sf::Vector2f(100,15));

    healthbarout.setPosition(100,50);
    healthbarin.setPosition(healthbarout.getPosition().x, healthbarout.getPosition().y + 2);


    healthtext.setFont(graphics::fontarial);
    healthtext.setCharacterSize(16);
    healthtext.setPosition((healthbarout.getPosition().x) + (healthbarout.getSize().x/4), healthbarout.getPosition().y - healthtext.getCharacterSize());
    healthtext.setString("Health");
    healthtext.setColor(sf::Color::Cyan);

}
void UI::display(sf::RenderWindow& window)
{
window.draw(healthbarout);
window.draw(healthbarin);
window.draw(healthtext);
}
void UI::update(Player& player)
{
    playerhealth = player.getHealth();

    if(playerhealth >= 0)
        healthbarin.setSize(sf::Vector2f(playerhealth, 15));

}
