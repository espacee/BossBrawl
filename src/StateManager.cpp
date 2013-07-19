#include "StateManager.hpp"

StateManager::StateManager()
{
    states.push_back(new MenuState);
    states.push_back(new GameState);

    SetCurrentState(MENU);
}

void StateManager::SetCurrentState(int newState)
{
    currentState = newState;
}

int StateManager::GetCurrentState() const
{
    return currentState;
}

void StateManager::Loop(sf::RenderWindow &w)
{
    currentState = states[currentState]->Loop(w);
}

StateManager::~StateManager()
{
    for (auto s : states)
    {
        delete s;
    }
}
