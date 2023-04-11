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
	class Operations;

	class Gallery
	{
	public:
		Gallery(const std::string& path, const Access& accessType);
		~Gallery();

		bool IsOpened() const { return m_db != nullptr; }
		const Access& GetAccessType() const { return m_access; }
		const std::filesystem::path& GetDbPath() const { return m_path; }
		std::filesystem::path GetGalleryPath() const;

		template<typename T>
		SQLite::Database* AccessDb(const T* obj) const
		{
			static_assert(
				std::is_same<std::remove_pointer_t<T>, tagallery::Item>::value ||
				std::is_same<std::remove_pointer_t<T>, tagallery::Tag>::value ||
				std::is_same<std::remove_pointer_t<T>, tagallery::TagType>::value ||
				std::is_same<std::remove_pointer_t<T>, tagallery::Operations>::value
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

	class Operations
	{
	public:
		Operations(const Gallery& owner) : m_owner(owner) { }
		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

		// Item.cpp
		std::vector< Item > GetItems(std::optional< std::string > filter = std::nullopt);

		// Tag.cpp
		std::vector< Tag > GetTags(std::optional< std::string > filter = std::nullopt);
		std::optional< Tag > FindTagById(const dbIdx& id);
		std::optional< Tag > FindTagByName(const std::string& tagName);
		std::optional< Tag > AddTag(const std::string& tagType, const std::string& tagName);

		// TagType.cpp
		std::vector< TagType > GetTypes(std::optional< std::string > filter = std::nullopt);
		std::optional< TagType > FindTypeById(const dbIdx& id);
		std::optional< TagType > FindTypeByName(const std::string& typeName);
		std::optional< TagType > AddTagType(const std::string& typeName);

	private:
		const Gallery& m_owner;
	};
}
