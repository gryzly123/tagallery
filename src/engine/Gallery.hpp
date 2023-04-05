#pragma once

#include <filesystem>
#include <memory>
#include <string>
#include <optional>

#include "Access.hpp"
#include "Internals.hpp"

namespace SQLite
{
	class Database;
}

namespace tagallery
{
	class Item;
	class Tag;
	class TagType;

	class Gallery
	{
	public:
		Gallery(const std::string& path, const Access& accessType);
		~Gallery();

		bool IsOpened() const { return m_db != nullptr; }
		const Access& GetAccessType() const { return m_access; }
		const std::filesystem::path& GetDbPath() const { return m_path; }

		template<typename T>
		SQLite::Database* AccessDb(const T* obj) const
		{
			static_assert(
				std::is_same<std::remove_pointer_t<T>, tagallery::Item>::value ||
				std::is_same<std::remove_pointer_t<T>, tagallery::Tag>::value ||
				std::is_same<std::remove_pointer_t<T>, tagallery::TagType>::value
			);

			if (obj && obj->OwnedBy(this) && IsOpened())
			{
				return m_db.get();
			}
			throw InvalidGalleryRef();
			return nullptr;
		}

	private:
		void BuildDatabase();
		void PopulateDatabase(bool skipExistingCheck = false);
		void LoadDatabase();

		const std::filesystem::path m_path;
		const Access m_access;
		std::unique_ptr< SQLite::Database > m_db;
	};

}
