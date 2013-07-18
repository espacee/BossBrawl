#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.hpp"

#include "MenuState.hpp"
#include "GameState.hpp"

class StateManager
{
public:
    StateManager();
    void SetCurrentState(int newState);
    int GetCurrentState();

    void Loop(sf::RenderWindow &w);

private:
    std::vector<State*> states;
    int currentState;
};

#endif // STATEMANAGER_H
