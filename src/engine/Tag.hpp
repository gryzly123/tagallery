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
		Tag(const Gallery& owner, const dbIdx& index);

		std::string GetName() const;
		void SetName( const std::string& name );

		TagType GetTagType() const;
		void SetTagType( const TagType& type ) const;

		size_t GetNumReferences() const;

		const dbIdx& GetIndex() const { return m_index; }

		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

		static std::string GetClass() { return "Tag"; }

	private:
		const Gallery& m_owner;
		const dbIdx m_index;
	};
}
