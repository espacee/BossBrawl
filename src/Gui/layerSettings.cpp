#include "Gui/layerSettings.hpp"
#include "Core/graphics.hpp"
#include "IconButton.hpp"
#include "Editor/EditorState.hpp"


LayerSettings::LayerSettings()
{
    rect.setSize(sf::Vector2f(200, 90));
    rect.setFillColor(sf::Color(200,200,200));

    showlayer.setIcon("res/img/GUI/layer.png");
    showgrid.setIcon("res/img/GUI/grid.png");

    more.setText(">>");
    more.setTextColor(sf::Color::White);
    more.setHeight(rect.getSize().y);
    more.setWidth(25);
    more.setCharacterSize(20);

    showlayer.setToggleable(true);
    showgrid.setToggleable(true);

    layername.setFont(graphics::font);
    layername.setString("Layer 0");
    layername.setCharacterSize(20);

    update();
}

void LayerSettings::update()
{
    layername.setPosition(rect.getPosition().x + 40, rect.getPosition().y + 15);
    showlayer.setPosition(rect.getPosition().x + 60, rect.getPosition().y + 50);
    showgrid.setPosition(rect.getPosition().x + 100, rect.getPosition().y + 50);
    more.setPosition(rect.getPosition().x +(rect.getSize().x / 7)*6 + 5, rect.getPosition().y );

}

void LayerSettings::display(sf::RenderTarget &target)
{
    update();

    target.draw(rect);
    target.draw(layername);

    showlayer.display(target);
    showgrid.display(target);
    more.display(target);
}

void LayerSettings::processEvents(const sf::Event &event)
{
    Widget::processEvents(event);
    showlayer.processEvents(event);
    showgrid.processEvents(event);
    more.processEvents(event);
}

