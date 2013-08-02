#ifndef LAYERSETTINGS_HPP
#define LAYERSETTINGS_HPP

#include "Gui/Widget.hpp"
#include "Gui/IconButton.hpp"
#include "Gui/TextButton.hpp"



class LayerSettings : public Widget
{
public:
    LayerSettings();

    void update();
    void display(sf::RenderTarget &target);
    void processEvents(const sf::Event &event);

    sf::RectangleShape rect;

private:
    sf::Text layername;
    IconButton showlayer;
    IconButton showgrid;
    TextButton more;

private:

};

#endif // LAYERSETTINGS_HPP
