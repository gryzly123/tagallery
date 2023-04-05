#pragma once

#include <optional>
#include <string>
#include <vector>

#include "Internals.hpp"

namespace tagallery
{
	class Gallery;
	class Tag;

	class Item
	{
	public:
		static std::vector< Item > GetItems(const Gallery& gallery, std::optional< std::string > filter);

		Item(const Gallery& owner, const dbIdx& index);

		std::string GetFileName() const;
		void SetFileName(const std::string& fileName);

		bool FileExists() const;

		std::vector< Tag > GetTags() const;
		void AddTag( const Tag& tag);
		void RemoveTag(const Tag& tag);

		const dbIdx& GetIndex() const { return m_index; }

		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

	private:
		const Gallery& m_owner;
		const dbIdx m_index;
	};
}
