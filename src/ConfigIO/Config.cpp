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
} // namespace ConfigIO