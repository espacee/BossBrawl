#include "stateDriver.hpp"

#include "graphics.hpp"

#include <map>
#include <iostream>

namespace stateDriver
{

bool m_running;
std::map<std::string, State*> m_states;
State* m_currentState;

int exec()
{
    m_running = true;

    while (m_running)
    {
        sf::Event event;

        while (graphics::window.pollEvent(event))
        {
            m_currentState->onEvent(event);

            if (event.type == sf::Event::Closed)
            {
                m_running = false;
            }
        }

        m_currentState->onUpdate();
        graphics::window.display();
    }

    return 0;
}

void addState(State *state, const std::string &name)
{
    m_states[name] = state;
}

void setState(const std::string &name)
{
    auto it = m_states.find(name);

    if (it == m_states.end())
    {
        std::cerr << "No such state: \"" << name << "\"\n";
        throw;
    }

    m_currentState = it->second;
    m_currentState->onSet();
}

void requestQuit()
{
    m_running = false;
}

}
