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
private:
    sf::Text layername;
    IconButton showlayer;
    IconButton showgrid;
    TextButton more;
    sf::RectangleShape rectmore;
    sf::RectangleShape rect;
    bool moreoptions;
};

#endif // LAYERSETTINGS_HPP
