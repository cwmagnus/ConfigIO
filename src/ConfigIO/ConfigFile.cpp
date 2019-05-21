#include <ConfigIO/ConfigFile.h>

#include <fstream>
#include <iostream>
#include <vector>

namespace ConfigIO
{
    void ConfigFile::Write(const std::string& fileName, Config& config)
    {
        std::ofstream configFile;
        configFile.open(fileName);
        configFile << config.Serialize();
        configFile.close();
    }

    Config ConfigFile::Read(const std::string& fileName)
    {
        std::map<std::string, std::map<std::string, std::string> > configData;

        std::ifstream configFile;
        configFile.open(fileName);

        // Parse the config file
        std::string line;
        std::string section;
        while (std::getline(configFile, line))
        {
            // Check if the line is a section otherwise try to read it as a key value pair
            if (line.find('[') != std::string::npos && line.find(']') != std::string::npos)
            {
                // Record the section name
                std::size_t endBracketPos = line.find(']');
                section = line.substr(1, endBracketPos - 1);
            }
            else
            {
                // Try to read the line as a key value pair
                std::stringstream lineStream(line);
                std::string segment;
                std::vector<std::string> pair;
                while(std::getline(lineStream, segment, '='))
                {
                    pair.push_back(segment);
                }

                // If the vector has a key and value then add it to the data map otherwise reset the section
                if (pair.size() == 2)
                {
                    configData[section][pair[0]] = pair[1];
                }
                else
                {
                    section = "";
                }
            }
        }

        return Config(configData);
    }
} // namespace ConfigIO
