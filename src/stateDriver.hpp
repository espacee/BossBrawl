#ifndef STATEDRIVER_HPP
#define STATEDRIVER_HPP

#include "State.hpp"

#include <string>

namespace stateDriver
{

void AddState(State* state, const std::string& name);
void SetState(const std::string& name);
int Exec();
void RequestQuit();

}

#endif // STATEDRIVER_HPP
