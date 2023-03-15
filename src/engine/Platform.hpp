#pragma once
#include <filesystem>
#include <chrono>
#include <optional>

namespace tagallery
{
    struct FileDates
    {
        std::time_t accessed;
        std::time_t created;
        std::time_t modified;
    };

    class Platform
    {
    public:
        static std::optional<FileDates> GetFileDates(const std::filesystem::directory_entry& file);
    };
}
