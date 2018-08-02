//
// Author: Jin Yuqi (Ricky)
// Email: 179386223@qq.com
// Date: 2018.08.02
//

#ifndef __SECONFIG__
#define __SECONFIG__

#include <string>
#include <map>

class SEConfig
{
public:
    SEConfig(const std::string &fileName);
    std::string stringOf(const std::string &key, const std::string &category = "Global");
    int intOf(const std::string &key, const std::string &category = "Global");
private:
    void loadConfigFile(const std::string &fileName);
    void processLine(const std::string &line);
    bool IsCategory(const std::string line) const;
    bool IsKeyValueLine(const std::string line) const;
    std::string getKeyFromLine(const std::string &line) const;
    std::string getValueFromLine(const std::string &line) const;
private:
    std::map<std::string, std::map<std::string, std::string>> m_cacheMap;
    std::string m_currentProcessCategory;
};

#endif
