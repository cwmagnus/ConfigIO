#include <ConfigIO/ConfigFile.h>

#include <fstream>

namespace ConfigIO
{
    void ConfigFile::Write(const std::string& configFileName, Config& config)
    {
        std::ofstream configFile;
        configFile.open(configFileName);
        configFile << config.Serialize();
        configFile.close();
    }
} // namespace ConfigIO
