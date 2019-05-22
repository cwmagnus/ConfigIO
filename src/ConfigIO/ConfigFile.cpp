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
            // Trim the lines whitespace and comments
            line = Trim(line);

            // Check if the line is a section otherwise try to read it as a key value pair
            std::size_t openBracketPosition = line.find('[');
            std::size_t closeBracketPosition = line.find(']');
            if (openBracketPosition != std::string::npos && closeBracketPosition != std::string::npos)
            {
                // Record the section name
                section = line.substr(openBracketPosition + 1, closeBracketPosition - 1);
            }
            else
            {
                // Try to read the key and value pair
                std::size_t delimiterPosition = line.find('=');
                if (delimiterPosition != std::string::npos)
                {
                    std::string key = line.substr(0, delimiterPosition);
                    std::string value = line.substr(delimiterPosition + 1);

                    if (value.find("\"") != std::string::npos)
                    {
                        value = value.substr(1, value.length() - 2);
                    }

                    configData[section][key] = value;
                }
            }
        }

        return Config(configData);
    }

    std::string ConfigFile::Trim(const std::string& string)
    {
        // Remove the comments from the string
        std::string trimmedString = string;
        const std::size_t commentPosition = string.find("#");
        if (commentPosition != std::string::npos)
        {
            trimmedString = trimmedString.substr(0, commentPosition);
        }

        // Remove whitespace from the string
        const std::size_t begin = trimmedString.find_first_not_of(" \t");
        if (begin == std::string::npos) 
        {
            return "";
        }
        const std::size_t end = trimmedString.find_last_not_of(" \t");
        const std::size_t range = end - begin + 1;

        return trimmedString.substr(begin, range);
    }
} // namespace ConfigIO
