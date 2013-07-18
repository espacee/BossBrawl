#ifndef CONFIG_HPP
#define CONFIG_HPP

/**
 *
 * @brief Configuration module
 *
 * The config module stores all settings that can be set by the user.
 * The config file format consists of simple key/value pairs.
 *
 */
namespace config
{

/**
 * @brief Load the configuration from the default configuration file
 *
 * It first loads the defaults, then, if the configuration file exists,
 * loads the configuration from it.
 */
void Load();

/**
 * @brief Save the configuration to the default configuration file
 */
void Save();

/**
 * @brief Width of the game window
 */
extern int windowWidth;

/**
 * @brief Height of the game window
 */
extern int windowHeight;

}

#endif // CONFIG_HPP
