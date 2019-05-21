#ifndef CONFIG_IO_CONFIG_H
#define CONFIG_IO_CONFIG_H

#include <string>
#include <sstream>
#include <map>

namespace ConfigIO
{
    /**
     * @brief Stores and retrieves data from a configuration file
     * 
     */
    class Config
    {
    public:
        /**
         * @brief Construct a new config data object
         * 
         */
        Config();

        /**
         * @brief Construct a new config data object
         * 
         * @param configData Data to populate the config object with
         */
        Config(const std::map<std::string, std::map<std::string, std::string> >& configData);

        ~Config();

        /**
         * @brief Gets a value from the config data
         * 
         * @tparam T Type of value to retrieve
         * @param section Section to get the value from
         * @param key Key that holds the value
         * @param defaultValue Default value to return if there is no matching section or key
         * @return T Value from the config data
         */
        template<typename T>
        T Get(const std::string& section, const std::string& key, T defaultValue) const;

        /**
         * @brief Sets a config data value
         * 
         * @tparam T Type of value to set
         * @param section Section of the value to set
         * @param key Key of the value to set
         * @param value Value to set
         */
        template<typename T>
        void Set(const std::string* section, const std::string& key, T value);

    private:
        std::map<std::string, std::map<std::string, std::string> > _configData;
    };

    template<typename T>
    inline T Config::Get(const std::string& section, const std::string& key, T defaultValue) const
    {
        // Check if the section exists
        auto sectionIT = _configData.find(section);
        if (sectionIT != _configData.end())
        {
            // Check if the key exists
            auto keyIT = sectionIT->second.find(key);
            if (keyIT != sectionIT->second.end())
            {
                // Convert the string value at the key to the template type
                std::stringstream stringValue(keyIT->second);
                T value;
                stringValue >> value;
                return value;
            }
        }

        // Return default value if can't find section or key
        return defaultValue;
    }
} // namespace ConfigIO

#endif // !CONFIG_IO_CONFIG_H