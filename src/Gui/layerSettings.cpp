#include "Gui/layerSettings.hpp"
#include "Core/graphics.hpp"
#include "IconButton.hpp"
#include "Editor/EditorState.hpp"



layerSettings::layerSettings()
{

    moreoptions = false;

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

    layername.setFont(graphics::fontbasiclight);
    layername.setString("Layer 0");
    layername.setCharacterSize(20);

    /** More Layer Options **/
    rectmore.setSize(sf::Vector2f(500,300));
    rectmore.setFillColor(sf::Color(100,100,100,200));

    moretitle.setString("Layer Options");
    moretitle.setFont(graphics::fontbasiclight);


    update();
}

void layerSettings::update()
{
    rect.setPosition(graphics::window.getSize().x-200-4, 110);
    layername.setPosition(rect.getPosition().x + 40, rect.getPosition().y + 15);
    showlayer.setPosition(rect.getPosition().x + 60, rect.getPosition().y + 50);
    showgrid.setPosition(rect.getPosition().x + 100, rect.getPosition().y + 50);
    more.setPosition(rect.getPosition().x +(rect.getSize().x / 7)*6 + 5, rect.getPosition().y );


    /** More Layer Options **/
     rectmore.setPosition((graphics::window.getSize().x /2) - (rectmore.getSize().x /2), (graphics::window.getSize().y / 2) - (rectmore.getSize().y /2));
     moretitle.setPosition(rectmore.getPosition().x + 5, rectmore.getPosition().y + 5);
}

void layerSettings::display(sf::RenderTarget &target)
{

    update();


    if(more.isPressed() || more.isReleased())
            moreoptions = true;

    target.draw(rect);
    target.draw(layername);

    showlayer.display(target);
    showgrid.display(target);
    more.display(target);

    if(moreoptions == true){
       target.draw(rectmore);
        target.draw(moretitle);
    }
}

void layerSettings::processEvents(const sf::Event &event)
{
    showlayer.processEvents(event);
    showgrid.processEvents(event);
    more.processEvents(event);

    if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) && isMoreOptionsActive() == true)
        moreoptions = false;


}
bool layerSettings::isMoreOptionsActive()
{
    return moreoptions;
}


