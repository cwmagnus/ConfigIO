#include <ConfigIO/Config.h>

namespace ConfigIO
{
    Config::Config()
    {

    }

    Config::Config(const std::map<std::string, std::map<std::string, std::string> >& configData) :
        _configData(configData)
    {

    }

    std::string Config::Serialize() const
    {
        std::stringstream serializedConfigData;

        for (auto sit = _configData.begin(); sit != _configData.end(); sit++)
        {
            serializedConfigData << '[' << sit->first << ']' << std::endl;
            for (auto kit = sit->second.begin(); kit != sit->second.end(); kit++)
            {
                serializedConfigData << kit->first << '=' << kit->second << std::endl;
            }
            serializedConfigData << std::endl;
        }

        return serializedConfigData.str();
    }
} // namespace ConfigIO