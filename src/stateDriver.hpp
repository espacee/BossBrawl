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

}

#endif // STATEDRIVER_HPP
