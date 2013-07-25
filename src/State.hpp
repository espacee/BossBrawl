#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief Base class for states
 */
class State
{
public :
    /**
     * @brief Called whenever the current state is set to this state
     */
    virtual void onSet() {}

    /**
     * @brief Called every frame
     */
    virtual void onUpdate() {}

    /**
     * @brief Called every time an event happens
     */
    virtual void onEvent(const sf::Event& event) {
        (void)(event);
    }

    virtual ~State() {}
};

#endif // STATE_HPP
