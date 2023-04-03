#pragma once

#include <optional>
#include <string>
#include <vector>

namespace tagallery
{
	class Gallery;
	class Tag;

	class Item
	{
	public:
		static std::vector< Item > GetItems(const Gallery& gallery, std::optional< std::string > filter);

		Item(const Gallery& owner, const size_t& index);

		std::string GetFileName() const;
		void SetFileName(const std::string& fileName);
		bool FileExists() const;
		std::vector< Tag > GetTags() const;
		void AddTag( const Tag& tag);
		const size_t& GetIndex() const { return m_index; }

	private:
		const Gallery& m_owner;
		const size_t m_index;

	};
}
