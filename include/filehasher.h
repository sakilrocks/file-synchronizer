
#ifndef FILEHASHER_H
#define FILEHASHER_H

#include <string>

class FileHasher {
public:
    static std::string hashFile(const std::string& path);
};


#endif 