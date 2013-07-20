#include "StateManager.hpp"

StateManager::StateManager()
{
    states.push_back(new MenuState);
    states.push_back(new GameState);
    states.push_back(new EditorState);

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

void StateManager::Loop()
{
    currentState = states[currentState]->Loop();
}

StateManager::~StateManager()
{
    for (auto s : states)
    {
        delete s;
    }
}
