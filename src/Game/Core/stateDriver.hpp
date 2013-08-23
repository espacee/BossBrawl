#ifndef CORE_STATEDRIVER_HPP
#define CORE_STATEDRIVER_HPP

#include "Game/Core/State.hpp"

#include <string>

/**
 * @brief The state driver module
 */
namespace stateDriver
{

void addState(State* state, const std::string& name);
void setState(const std::string& name);
int exec();
void requestQuit();
int getFps();

/**
 * @brief Delete all owned states
 *
 * Used before quit, to ensure proper cleanup
 */
void deleteStates();

}

#endif // CORE_STATEDRIVER_HPP
