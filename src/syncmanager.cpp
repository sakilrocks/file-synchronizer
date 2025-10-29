
#include "../include/syncmanager.h"
#include "../include/filescanner.h"
#include <filesystem>
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

namespace fs = std::filesystem;

void SyncManager::syncDirectories(const std::string& source, const std::string& dest, int threadCount) {
    auto srcFiles = FileScanner::scanDirectory(source);
    auto destFiles = FileScanner::scanDirectory(dest);

    std::queue<std::pair<std::string, std::string>> tasks;
    for (const auto& [relative, hash] : srcFiles) {
        auto destPath = fs::path(dest) / relative;
        if (!destFiles.count(relative) || destFiles[relative] != hash) {
            tasks.push({fs::path(source) / relative, destPath.string()});
        }
    }

    std::mutex queueMutex;
    std::mutex coutMutex;

    auto worker = [&]() {
        while (true) {
            std::pair<std::string, std::string> task;
            {
                std::lock_guard<std::mutex> lock(queueMutex);
                if (tasks.empty()) break;
                task = tasks.front();
                tasks.pop();
            }

            fs::create_directories(fs::path(task.second).parent_path());
            try {
                fs::copy_file(task.first, task.second, fs::copy_options::overwrite_existing);
                std::lock_guard<std::mutex> lock(coutMutex);
                std::cout << "[+] copied: " << task.first << " -> " << task.second << "\n";
            } catch (...) {
                std::lock_guard<std::mutex> lock(coutMutex);
                std::cerr << "[!] failed to copy: " << task.first << "\n";
            }
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < threadCount; ++i)
        threads.emplace_back(worker);

    for (auto& t : threads)
        t.join();

    std::cout << "sync completed. " << tasks.size() << " files processed.\n";
}