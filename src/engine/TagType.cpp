#include "SQLiteCpp/SQLiteCpp.h"

#include "Gallery.hpp"
#include "TagType.hpp"

namespace tagallery
{
	std::vector<TagType> Operations::GetTypes(std::optional<std::string> filter)
	{
		std::vector<TagType> result;
		auto* db = m_owner.AccessDb(this);

		SQLite::Statement sql(*db, "SELECT id FROM tagType WHERE name LIKE ?");
		sql.bind(1, filter.value_or("") + "%");

		while (sql.executeStep())
		{
			int64_t id = sql.getColumn(0);
			result.push_back(TagType(m_owner, id));
		}

		return result;
	}

	std::optional<TagType> Operations::FindTypeById(const dbIdx& id)
	{
		auto* db = m_owner.AccessDb(this);
		SQLite::Statement sql(*db, "SELECT id FROM tagType WHERE id == ?");
		sql.bind(1, id);

		if (sql.executeStep())
		{
			ThrowIfNotDone(sql);
			return TagType(m_owner, id);
		}

		return std::nullopt;
	}

	std::optional<TagType> Operations::FindTypeByName(const std::string& typeName)
	{
		if (!TagType::ValidateName(typeName))
		{
			throw InvalidName(typeName);
		}

		auto* db = m_owner.AccessDb(this);
		SQLite::Statement sql(*db, "SELECT id FROM tagType WHERE name == ?");
		sql.bind(1, typeName);

		if (sql.executeStep())
		{
			int64_t id = sql.getColumn(0);
			ThrowIfNotDone(sql);
			return TagType(m_owner, id);
		}

		return std::nullopt;
	}

	std::optional<TagType> Operations::AddTagType(const std::string& typeName)
	{
		auto* db = m_owner.AccessDb(this);
		SQLite::Statement sql(*db, "INSERT INTO tagType(name) VALUES(?)");
		sql.bind(1, typeName);
		if (sql.exec() != 1)
		{
			throw AlreadyExists("TagType of name: " + typeName);
		}

		return FindTypeByName(typeName);
	}

	TagType::TagType(const Gallery& owner, const dbIdx& index)
		: m_owner(owner)
		, m_index(index)
	{
		if (!m_owner.IsOpened())
		{
			throw InvalidGalleryRef();
		}
	}

	std::string TagType::GetName() const
	{
		std::string result;

		auto* db = m_owner.AccessDb(this);
		SQLite::Statement sql(*db, "SELECT name FROM tagType WHERE id == ?");
		sql.bind(1, m_index);

		if (!sql.executeStep())
		{
			//throw NotFound(this);
		}

		const char* r = sql.getColumn(0);
		result = r;
		ThrowIfNotDone(sql);
		return result;
	}

	void TagType::SetName(const std::string& typeName)
	{
		if (!m_owner.GetAccessType().CanModifyTags())
		{
			throw CannotModifyTags();
		}

		if (!ValidateName(typeName))
		{
			throw InvalidName(typeName);
		}

		auto* db = m_owner.AccessDb(this);
		SQLite::Transaction transaction(*db);

		SQLite::Statement sql(*db, "UPDATE tagType SET name = ? WHERE id == ?");
		sql.bind(1, typeName);
		sql.bind(2, m_index);

		switch (sql.exec())
		{
			case 0:
				//throw NotFound(this);
				return;

			case 1:
				transaction.commit();
				return;

			default:
				throw MultipleItemsFound();
				return;
		}
	}

	size_t TagType::GetNumReferences() const
	{
		throw NotImplemented("TagType::GetNumReferences()");
	}

	bool TagType::ValidateName(const std::string& typeName)
	{
		constexpr char invalidChars[] = {' ', ':', '\'', '\"', '\\', '%'};
		for (char c : invalidChars)
		{
			if (typeName.find(c) != std::string::npos)
			{
				return false;
			}
		}
		return true;
	}
}
