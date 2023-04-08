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
		TagType(const Gallery& owner, const dbIdx& index);

		std::string GetName() const;
		void SetName(const std::string& typeName);

		const dbIdx& GetIndex() const { return m_index; }

		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

		static std::string GetClass() { return "TagType"; }
		static bool ValidateName(const std::string& typeName);

	private:
		const Gallery& m_owner;
		const dbIdx m_index;
	};
}
