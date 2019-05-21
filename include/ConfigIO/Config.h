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
        void Set(const std::string& section, const std::string& key, T value);

        /**
         * @brief Serializes the config structure into a config file structure
         * 
         * @return std::string Serialized config file contents
         */
        std::string Serialize() const;

    private:
        std::map<std::string, std::map<std::string, std::string> > _configData;
    };

    template<typename T>
    inline T Config::Get(const std::string& section, const std::string& key, T defaultValue) const
    {
        // Check if the section exists
        auto sit = _configData.find(section);
        if (sit != _configData.end())
        {
            // Check if the key exists
            auto kit = sit->second.find(key);
            if (kit != sit->second.end())
            {
                // Convert the string value at the key to the template type
                std::stringstream stringValue(kit->second);
                T value;
                stringValue >> value;
                return value;
            }
        }

        // Return default value if can't find section or key
        return defaultValue;
    }

    template<typename T>
    inline void Config::Set(const std::string& section, const std::string& key, T value)
    {
        // Create or set the value
        _configData[section][key] = std::to_string(value);
    }
} // namespace ConfigIO

#endif // !CONFIG_IO_CONFIG_H
