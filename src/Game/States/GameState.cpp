#include "GameState.hpp"
#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"


GameState::GameState() :
    gridEnabled(false)
{
    map.loadFromFile("res/maps/test.map"); //LOADS MAP
    entityContainer.loadFromFile("res/maps/test.entity"); //LOADS ENTITIES
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    fpsText.setFont(graphics::fontbasiclight);
    fpsText.setCharacterSize(16);
    ui.onInit(); //INIT VAN UI
}

void GameState::onSet()
{
    graphics::window.setTitle("game");
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    camera.setCenter(0, 0);
    fpsText.setPosition(5, graphics::window.getSize().y - 20);
}

void GameState::onUpdate()
{
    using graphics::window;

    player.updatePlayer(map[0]); //Update player op MAINLayer **MAINLAYER(VOOR COLLISION) IS STEEDS 0**
    ui.update(player); //Update UI met parameter Player voor HEALTH
    entityContainer.updateEntities(map[0]); //Update alle entities op MAINlayer **MAIN steeds 0**
	if (!viewerEnabled) { //ALS VIEWERMODE TRUE IS, VIEW NIET UPDATEN
		util::moveViewTowardsPoint(camera, player.getCenter(), 0.05); //Camera volgt PLAYER
	}
    window.clear(sf::Color(80, 80, 80));
    graphics::window.setView(camera); //BIND CAMERA OP WINDOW
    map.draw(window, (gridEnabled ? 0 : -1));
    player.display(window);
    entityContainer.displayEntities(window);
    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));
    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);
    ui.display(window);

	
}

void GameState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
            stateDriver::setState("menu");
            break;

		case sf::Keyboard::Subtract:
			camera.zoom(0.5f);
            break;

		case sf::Keyboard::Add:
			camera.zoom(2);
            break;

        case sf::Keyboard::G:
            gridEnabled = !gridEnabled;
            break;

        case sf::Keyboard::P: {
            player.heal(10);
            std::cout << "PlayerHealth: " << player.getHealth() << std::endl;
        }
		 break;

        case sf::Keyboard::O:
        {
            player.damage(10);
            std::cout << "PlayerHealth: " << player.getHealth() << std::endl;
        }
        break;
		case sf::Keyboard::V:
		{
			viewerEnabled = !viewerEnabled;
			std::cout << "Viewermode: " << viewerEnabled <<  std::endl;
		}
		break;

		case sf::Keyboard::Numpad8: //START HERE FOR VIEWER
		{
			util::gameViewerMove(camera, sf::Vector2f(0,-40), 1);

		}
		break;
		case sf::Keyboard::Numpad6:
		{
			util::gameViewerMove(camera, sf::Vector2f(20, 0), 1);
		}
		break;
		case sf::Keyboard::Numpad2:
		{
			util::gameViewerMove(camera, sf::Vector2f(0, 20), 1);
		}
		break;
		case sf::Keyboard::Numpad4:
		{
			util::gameViewerMove(camera, sf::Vector2f(-20, 0), 1);
		}
		break;

        default:
            ;
        }
    }
}
