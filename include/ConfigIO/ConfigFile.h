#ifndef CONFIG_IO_CONFIG_FILE_H
#define CONFIG_IO_CONFIG_FILE_H

#include <ConfigIO/Config.h>

namespace ConfigIO
{
    /**
     * @brief Handles reading and writing config files
     * 
     */
    class ConfigFile
    {
    public:
        /**
         * @brief Writes out to a config file
         * 
         * @param fileName Config file to write to
         * @param config Config structure to write contents from
         */
        static void Write(const std::string& fileName, Config& config);

        /**
         * @brief Reads a config file into a config structure
         * 
         * @param fileName Config file to read
         * @return Config Output config structure with loaded data
         */
        static Config Read(const std::string& fileName);
    };
} // namespace ConfigIO

#endif // !CONFIG_IO_CONFIG_FILE_H
