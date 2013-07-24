#ifndef STATEDRIVER_HPP
#define STATEDRIVER_HPP

#include "State.hpp"

#include <string>

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

#endif // STATEDRIVER_HPP
