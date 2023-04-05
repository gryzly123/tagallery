#pragma once

#include <optional>
#include <string>
#include <vector>

#include "Internals.hpp"

namespace tagallery
{
	class Gallery;

	class TagType
	{
	public:
		static std::vector< TagType > GetTypes(const Gallery& gallery, std::optional< std::string > filter);
		static std::optional< TagType > FindTypeById(const Gallery& gallery, const size_t& id);
		static std::optional< TagType > FindTypeByName(const Gallery& gallery, const std::string name);
		static std::optional< TagType > AddTagType(const Gallery& gallery, const std::string typeName);
		TagType(const Gallery& owner, const dbIdx& index);

		std::string GetName() const;
		void SetName(const std::string& name);

		const dbIdx& GetIndex() const { return m_index; }

		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

	private:
		const Gallery& m_owner;
		const dbIdx m_index;
	};
}
