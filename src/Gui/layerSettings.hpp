#ifndef LAYERSETTINGS_HPP
#define LAYERSETTINGS_HPP

#include "Gui/Widget.hpp"
#include "Gui/IconButton.hpp"
#include "Gui/TextButton.hpp"

class layerSettings : public Widget
{
public:
    layerSettings();

    void update();
    void display(sf::RenderTarget &target);
    void processEvents(const sf::Event &event);

    bool isMoreOptionsActive();
    sf::Vector2f getPositionRect();

    sf::RectangleShape rect;
private:
    sf::Text layername;
    IconButton showlayer;
    IconButton showgrid;
    TextButton more;
    sf::RectangleShape rectmore;

    /** More Layer Options **/

    sf::Text moretitle;

    bool moreoptions;
};

#endif // LAYERSETTINGS_HPP
