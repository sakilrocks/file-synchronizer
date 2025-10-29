
#include "../include/syncmanager.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "usage: " << argv[0] << " <source_dir> <destination_dir> [threads]\n";
        return 1;
    }

    std::string source = argv[1];
    std::string dest = argv[2];
    int threads = (argc >= 4) ? std::stoi(argv[3]) : 4;

    SyncManager::syncDirectories(source, dest, threads);
    return 0;
}