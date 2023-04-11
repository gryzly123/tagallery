#include "Gallery.hpp"
#include "Tag.hpp"
#include "TagType.hpp"

namespace tagallery
{
	std::vector<Tag> Operations::GetTags(std::optional<std::string> filter)
	{
		throw NotImplemented("Tag::GetTags");
		return std::vector<Tag>();
	}

	std::optional<Tag> Operations::FindTagById(const dbIdx& id)
	{
		throw NotImplemented("Tag::FindTagById");
		return std::nullopt;
	}

	std::optional<Tag> Operations::FindTagByName(const std::string& tagName)
	{
		throw NotImplemented("Tag::FindTagByName");
		return std::nullopt;
	}

	std::optional<Tag> Operations::AddTag(const std::string& tagType, const std::string& tagName)
	{
		throw NotImplemented("Tag::AddTag");
		return std::nullopt;
	}

	Tag::Tag(const Gallery& owner, const dbIdx& index)
		: m_owner(owner)
		, m_index(index)
	{
		if (!m_owner.IsOpened())
		{
			throw InvalidGalleryRef();
		}
	}

	std::string Tag::GetName() const
	{
		throw NotImplemented("Tag::GetName");
		return std::string();
	}

	void Tag::SetName(const std::string& name)
	{
		if (!m_owner.GetAccessType().CanModifyTags())
		{
			throw CannotModifyTags();
		}

		throw NotImplemented("Tag::SetName");
	}

	TagType Tag::GetTagType() const
	{
		throw NotImplemented("Tag::GetTagType");
		return TagType(m_owner, INVALID_REF);
	}

	void Tag::SetTagType(const TagType& type) const
	{
		if (!m_owner.GetAccessType().CanModifyTags())
		{
			throw CannotModifyTags();
		}

		throw NotImplemented("Tag::SetTagType");
	}

	size_t Tag::GetNumReferences() const
	{
		throw NotImplemented("Tag::GetNumReferences");
	}
}
