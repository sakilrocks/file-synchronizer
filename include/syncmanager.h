
#ifndef SYNCMANAGER_H
#define SYNCMANAGER_H

#include <string>

class SyncManager {
public:
    static void syncDirectories(const std::string& source, const std::string& dest, int threadCount = 4);
};


#endif 