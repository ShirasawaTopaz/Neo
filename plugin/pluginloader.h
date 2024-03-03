/// 负责处理插件加载
/// Container 是一个容器类，用于存储，运行和管理插件

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <cstdlib>
#include <memory>
#include <string>

struct PlugInfo
{
    std::string name;
    std::string author;
    std::string version;
    std::string file;
    std::string path;
};

class Container
{
private:
    std::unique_ptr<PlugInfo> info;
public:
    Container(const std::string& file);
    Container();
    ~Container();
};

#endif
