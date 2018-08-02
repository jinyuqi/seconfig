#include "seconfig.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

SEConfig::SEConfig(const std::string &fileName)
{
    loadConfigFile(fileName);
}

void SEConfig::loadConfigFile(const std::string &fileName)
{
    ifstream configFile(fileName);
    string line;
    if (configFile.is_open())
    {
        while (getline(configFile, line))
        {
            processLine(line);
        }
        configFile.close();
    }
}

void SEConfig::processLine(const std::string &line)
{
    if (IsCategory(line))
    {
        auto j = line.find('[');
        auto k = line.find(']');
        std::string category = line.substr(line.find('[') + 1, line.find(']') - line.find('[') - 1);

        if (!category.empty())
        {
            m_currentProcessCategory = category;
        }
    }
    else if (IsKeyValueLine(line))
    {
        auto key = getKeyFromLine(line);
        auto value = getValueFromLine(line);

        if (!key.empty() && !value.empty())
        {
            m_cacheMap[m_currentProcessCategory][key] = value;
        }
    }
}

std::string SEConfig::getKeyFromLine(const std::string &line) const
{
    auto tempRes = line.substr(0, line.find('='));
    tempRes.erase(remove_if(tempRes.begin(), tempRes.end(), ::isspace), tempRes.end());
    return tempRes;
}

std::string SEConfig::getValueFromLine(const std::string &line) const
{
    string tempRes = line.substr(line.find('=') + 1);

    tempRes.erase(remove_if(tempRes.begin(), tempRes.end(), ::isspace), tempRes.end());

    return tempRes;
}

bool SEConfig::IsKeyValueLine(const std::string line) const
{
    if (line.find('=') != string::npos && std::count(line.begin(), line.end(), '=') == 1)
    {
        return true;
    }

    return false;
}

bool SEConfig::IsCategory(const std::string line) const
{
    if (line.find('[') != string::npos && line.find(']') != string::npos)
    {
        return true;
    }

    return false;
}

std::string SEConfig::stringOf(const std::string &key, const std::string &category)
{
    if (m_cacheMap.find(category) != m_cacheMap.end())
    {
        if (m_cacheMap[category].find(key) != m_cacheMap[category].end())
            return m_cacheMap[category][key];
    }

    return string();
}

int SEConfig::intOf(const std::string &key, const std::string &category)
{
    if (m_cacheMap.find(category) != m_cacheMap.end())
    {
        if (m_cacheMap[category].find(key) != m_cacheMap[category].end())
            return atoi(m_cacheMap[category][key].data());
    }

    return 0;
}

