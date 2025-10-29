
#include "../include/filehasher.h"

#include <openssl/sha.h>
#include <fstream>
#include <sstream>
#include <iomanip>

std::string FileHasher::hashFile(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return "";

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    char buffer[8192];
    while (file.good()) {
        file.read(buffer, sizeof(buffer));
        SHA256_Update(&ctx, buffer, file.gcount());
    }

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &ctx);

    std::ostringstream oss;
    for (unsigned char c : hash)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)c;

    return oss.str();
}