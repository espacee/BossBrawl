#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

class State
{
public :
    /**
     * @brief Called whenever the current state is set to this state
     */
    virtual void OnSet() {}

    /**
     * @brief Called every frame
     */
    virtual void OnUpdate() {}

    /**
     * @brief Called every time an event happens
     */
    virtual void OnEvent(const sf::Event& event) {
        (void)(event);
    }

    virtual ~State() {}
};

#endif // STATE_HPP
