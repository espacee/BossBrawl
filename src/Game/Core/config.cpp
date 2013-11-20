#include "config.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

namespace config
{

unsigned int resolutionMode;

const char* const DEFAULT_CONFIG_FILENAME = "settings.cfg";

void setDefaults()
{
    resolutionMode = 0;
}

template <typename T>
void extract_assert(std::istream& stream, T& value)
{
    if (!(stream >> value))
    {
        std::cerr << "Failed extracting value";
        throw;
    }
}

void load()
{
    setDefaults();
    std::ifstream file(DEFAULT_CONFIG_FILENAME);

    if (!file)
    {
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream stream(line);
        std::string key;

        if (!(stream >> key))
        {
            std::cerr << "Failed extracting key\n";
            throw;
        }

        if (key == "resolutionMode")
        {
            extract_assert(stream, resolutionMode);
        }
        else
        {
            std::cerr << "Unknown key: \"" << key << "\"\n";
        }
    }
}

void save()
{
    std::ofstream file(DEFAULT_CONFIG_FILENAME);

    if (!file)
    {
        std::cerr << "Failed opening \"" << DEFAULT_CONFIG_FILENAME << "\" for writing.\n";
        return;
    }

    file << "resolutionMode " << resolutionMode << '\n';
}

} // end namespace config
