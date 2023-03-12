#pragma once

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace SQLite
{
	class Database;
}

namespace tagallery
{
	struct Access
	{
		constexpr static uint8_t ReadOnly = 0;    // only read and query the database
		constexpr static uint8_t MofifyTags = 1;  // can edit the database but cannot touch the files. Can react to directory changes
		constexpr static uint8_t MofifyFiles = 2; // can edit the database and files (rename, delete)
		constexpr static uint8_t Create = 4;      // can create the database if it doesn't exist

		uint8_t m_value;

		constexpr Access()
			: m_value(ReadOnly)
		{
		}
		
		constexpr Access(const uint8_t& value)
			: m_value(value)
		{
		}

		constexpr operator uint8_t() const
		{
			return m_value;
		}
	};

	class TagType
	{
	public:
		static std::optional< TagType > FindTypeById(const size_t& id);
		static std::optional< TagType > FindTypeByName(const std::string name);
	private:
		const std::string m_typeName;
		const size_t m_index;

		static std::vector< TagType > s_types;
	};

	class Tag
	{
	public:

	private:
		const TagType& m_value;
		std::string m_name;
	};

	class Item
	{
	public:
		enum class Status
		{
			Exists,
			Missing,
		};

	private:
		const std::string m_path;
		Status m_status;
		std::vector< Tag > m_tags;
	};

	class Gallery
	{
	public:
		

		Gallery(const std::string& path, const Access& accessType);
		~Gallery();

		bool IsOpened() const { return m_db != nullptr; }
		const Access& GetAccessType() const { return m_access; }
		const std::string& GetDbPath() const { return m_path; }

	private:

		const std::string m_path;
		const Access m_access;
		std::unique_ptr< SQLite::Database > m_db;

		std::unordered_map<std::string, Item> m_items;
	};

}


