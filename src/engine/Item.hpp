#pragma once

#include <filesystem>
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
		Item(const Gallery& owner, const dbIdx& index);

		std::string GetFileName() const;
		void SetFileName(const std::string& fileName);
		void RemoveFile();

		std::filesystem::path GetAbsoluteFilePath() const;
		bool FileExists() const;

		std::vector< Tag > GetTags() const;
		void AddTag(const Tag& tag);
		bool HasTag( const Tag& tag);
		void RemoveTag(const Tag& tag);

		const dbIdx& GetIndex() const { return m_index; }

		bool OwnedBy(const Gallery* gallery) const { return gallery == &m_owner; }

		static std::string GetClass() { return "Item"; }

	private:
		const Gallery& m_owner;
		const dbIdx m_index;
	};
}
