#ifndef CORE_STATE_HPP
#define CORE_STATE_HPP

#include <SFML/Graphics.hpp>

#include "Util/unused.hpp"

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
        BRAWL_UNUSED(event);
    }

    virtual ~State() {}
};

#endif // CORE_STATE_HPP
