#pragma once

#include <optional>
#include <string>
#include <vector>

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
		
		Tag(const Gallery& owner, const size_t& index);

		std::string GetName() const;
		void SetName( const std::string& name );

		TagType GetTagType() const;
		void SetTagType( const TagType& type ) const;

		const size_t& GetIndex() const { return m_index; }

	private:
		const Gallery& m_owner;
		const size_t m_index;
	};
}
