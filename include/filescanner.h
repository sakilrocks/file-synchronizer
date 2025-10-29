
#ifndef FILESCANNER_H
#define FILESCANNER_H

#include <string>
#include <unordered_map>

class FileScanner {
public:
    static std::unordered_map<std::string, std::string> scanDirectory(const std::string& root);
};


#endif 