#include <windows.h>

#include "Platform.hpp"

namespace tagallery
{
    std::optional<FileDates> Platform::GetFileDates(const std::filesystem::directory_entry& file)
    {
        const std::wstring path = file.path();
        HANDLE hFile = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            return std::nullopt;
        }

        FILETIME createdTime, accessedTime, modifiedTime;
        if (GetFileTime(hFile, &createdTime, &accessedTime, &modifiedTime) == 0)
        {
            CloseHandle(hFile);
            return std::nullopt;
        }

        auto toTimeT = [](const FILETIME& fileTime) -> std::time_t {
            ULARGE_INTEGER largeInt;
            largeInt.LowPart = fileTime.dwLowDateTime;
            largeInt.HighPart = fileTime.dwHighDateTime;
            return static_cast<std::time_t>((largeInt.QuadPart - 116444736000000000) / 10000000);
        };

        FileDates dates;
        dates.created = toTimeT(createdTime);
        dates.modified = toTimeT(modifiedTime);
        dates.accessed = toTimeT(accessedTime);

        CloseHandle(hFile);
        return dates;
    }
}
