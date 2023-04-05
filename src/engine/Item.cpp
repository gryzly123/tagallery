#include "SQLiteCpp/SQLiteCpp.h"

#include "Item.hpp"
#include "Gallery.hpp"
#include "Tag.hpp"

namespace tagallery
{
	std::vector<Item> Item::GetItems(const Gallery& gallery, std::optional<std::string> filter)
	{
		throw NotImplemented("Item::GetItems");
		return std::vector<Item>();
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
		SQLite::Statement exists(*db, "SELECT filename FROM item WHERE id == ?");
		exists.bind(1, m_index);

		if (exists.executeStep())
		{
			const char* r = exists.getColumn(0);
			result = r;
			ThrowIfNotDone(exists);
			return result;
		}
		throw InvalidGalleryRef();
	}

	void Item::SetFileName(const std::string& fileName)
	{
		throw NotImplemented("Item::SetFileName");
	}

	bool Item::FileExists() const
	{
		throw NotImplemented("Item::FileExists");
		return false;
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

	void Item::RemoveTag(const Tag& tag)
	{
		throw NotImplemented("Item::RemoveTag");
	}
}
