#include "SQLiteCpp/SQLiteCpp.h"

#include "Item.hpp"
#include "Gallery.hpp"
#include "Tag.hpp"

namespace tagallery
{
	std::vector<Item> Operations::GetItems(std::optional<std::string> filter)
	{
		if (filter.has_value())
		{
			throw NotImplemented("Item::GetItems with filter");
		}

		std::vector<Item> result;
		auto* db = m_owner.AccessDb(this);
		SQLite::Statement sql(*db, "SELECT id FROM item");

		while (sql.executeStep())
		{
			int64_t id = sql.getColumn(0);
			result.push_back(Item(m_owner, id));
		}

		return result;
	}

	Item::Item(const Gallery& owner, const dbIdx& index)
		: m_owner(owner)
		, m_index(index)
	{
		if (!m_owner.IsOpened())
		{
			throw InvalidGalleryRef();
		}
	}

	std::string Item::GetFileName() const
	{
		std::string result;

		auto* db = m_owner.AccessDb(this);
		SQLite::Statement sql(*db, "SELECT filename FROM item WHERE id == ?");
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

	void Item::SetFileName(const std::string& fileName)
	{
		throw NotImplemented("Item::SetFileName");
	}

	std::filesystem::path Item::GetAbsoluteFilePath() const
	{
		auto dirPath = m_owner.GetGalleryPath();
		return dirPath / GetFileName();
	}

	bool Item::FileExists() const
	{
		auto path = GetAbsoluteFilePath();
		return std::filesystem::exists(path);
	}

	std::vector<Tag> Item::GetTags() const
	{
		throw NotImplemented("Item::GetTags");
		return std::vector<Tag>();
	}

	void Item::AddTag(const Tag& tag)
	{
		throw NotImplemented("Item::AddTag");
	}

	bool Item::HasTag(const Tag& tag)
	{
		throw NotImplemented("Item::HasTag");
	}

	void Item::RemoveTag(const Tag& tag)
	{
		throw NotImplemented("Item::RemoveTag");
	}
}
