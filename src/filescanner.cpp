
#include "../include/filescanner.h"
#include "../include/filehasher.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::unordered_map<std::string, std::string> FileScanner::scanDirectory(const std::string& root) {
    std::unordered_map<std::string, std::string> files;

    for (auto& p : fs::recursive_directory_iterator(root)) {
        if (fs::is_regular_file(p.path())) {
            try {
                std::string relative = fs::relative(p.path(), root).string();
                files[relative] = FileHasher::hashFile(p.path().string());
            } catch (...) {
                std::cerr << "error reading: " << p.path() << "\n";
            }
        }
    }
    return files;
}