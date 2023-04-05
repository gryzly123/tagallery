#pragma once

#include <optional>
#include <string>
#include <vector>

#include "Internals.hpp"

namespace tagallery
{
	class Gallery;
	class TagType;

	class Tag
	{
	public:
		static std::vector< Tag > GetTags(const Gallery& gallery, std::optional< std::string > filter);
		static std::optional< Tag > FindTagById(const Gallery& gallery, const size_t& id);
		static std::optional< Tag > FindTagByName(const Gallery& gallery, const std::string& name);
		static std::optional< Tag > AddTag(const Gallery& gallery, const std::string& tagType, const std::string& name);
		
		Tag(const Gallery& owner, const dbIdx& index);

		std::string GetName() const;
		void SetName( const std::string& name );

		TagType GetTagType() const;
		void SetTagType( const TagType& type ) const;

		const dbIdx& GetIndex() const { return m_index; }

		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

	private:
		const Gallery& m_owner;
		const dbIdx m_index;
	};
}
