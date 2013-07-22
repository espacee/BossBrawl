#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Editor
{
public:
    Editor();
    void init();
    void display();
    void processEvents(const sf::Event &event);
    void setEnabled(bool enable);
    bool getEnabled() const;

private:
    sf::RectangleShape topPanel;
    Button penButton;
    Button eraserButton;
    Button fillButton;
    Button handButton;

    bool enabled;

};


#endif //!EDITOR_HPP
