#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "state.h"

#include "menustate.h"
#include "gamestate.h"

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
