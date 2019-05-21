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
         * @param configFileName Config file to write to
         * @param config Config structure to write contents from
         */
        static void Write(const std::string& configFileName, Config& config);
    };
} // namespace ConfigIO

#endif // !CONFIG_IO_CONFIG_FILE_H
