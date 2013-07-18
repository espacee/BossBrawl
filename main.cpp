#include <SFML/Graphics.hpp>
#include "statesList.h"

int main(int argc, char** argv)
{
    std::vector<State*> states;
    int currentState = GAME;

    sf::RenderWindow w(sf::VideoMode(800, 600, 32), "window");
    w.setFramerateLimit(60);

        MenuState s1;
        states.push_back (&s1);
        GameState s2;
        states.push_back (&s2);

    while (currentState != EXIT)
    {
        currentState = states[currentState]->Loop(w);
    }

    return 0;
}
