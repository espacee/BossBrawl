#include "config.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

namespace config
{

int windowWidth;
int windowHeight;

const char* const DEFAULT_CONFIG_FILENAME = "settings.cfg";

void setDefaults()
{
    windowWidth = 1280;
    windowHeight = 720;
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

void Load()
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

        if (key == "screenWidth")
        {
            extract_assert(stream, windowWidth);
        }

        else if (key == "screenHeight")
        {
            extract_assert(stream, windowHeight);
        }

        else
        {
            std::cerr << "Unknown key: \"" << key << "\"\n";
        }
    }
}

void Save()
{
    std::ofstream file(DEFAULT_CONFIG_FILENAME);

    if (!file)
    {
        std::cerr << "Failed opening \"" << DEFAULT_CONFIG_FILENAME << "\" for writing.\n";
        return;
    }

    file << "screenWidth " << windowWidth << '\n'
         << "screenHeight " << windowHeight << '\n';
}

}
