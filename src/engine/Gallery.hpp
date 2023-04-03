#pragma once

#include <filesystem>
#include <memory>
#include <string>
#include <optional>

#include "Access.hpp"

namespace SQLite
{
	class Database;
}

namespace tagallery
{
	constexpr size_t INVALID_REF = std::numeric_limits<size_t>::max();

	class NotImplemented : public std::logic_error
	{
	public:
		NotImplemented( const std::string& methodName = "")
			: std::logic_error("Method " + methodName + " not implemented")
		{
		};
	};

	class InvalidGalleryRef : public std::logic_error
	{
	public:
		InvalidGalleryRef() : std::logic_error("Gallery reference was not valid")
		{
		};
	};

	class Gallery
	{
	public:
		Gallery(const std::string& path, const Access& accessType);
		~Gallery();

		bool IsOpened() const { return m_db != nullptr; }
		const Access& GetAccessType() const { return m_access; }
		const std::filesystem::path& GetDbPath() const { return m_path; }

	private:
		void BuildDatabase();
		void PopulateDatabase(bool skipExistingCheck = false);
		void LoadDatabase();

		const std::filesystem::path m_path;
		const Access m_access;
		std::unique_ptr< SQLite::Database > m_db;
	};

}


