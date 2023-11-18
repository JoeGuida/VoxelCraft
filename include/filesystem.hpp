#ifndef VOXELCRAFT_FILESYSTEM_HPP
#define VOXELCRAFT_FILESYSTEM_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class FileSystem final {
private:
    static std::string getRoot() {
        const char* env = std::getenv("VOXELCRAFT_ROOT");

        if (!env) {
            std::cout << "ERROR::FILESYSTEM Error reading environment variable: VOXELCRAFT_ROOT" << std::endl;
            return nullptr;
        }
        return std::string(env);
    }

public:
    static std::string getPath(const char* path) {
        std::string root = getRoot();

        if (root.empty())
            return nullptr;

        return std::string(root + path);
    }
};

#endif
