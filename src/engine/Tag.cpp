#include "Gallery.hpp"
#include "Tag.hpp"
#include "TagType.hpp"

namespace tagallery
{
	std::vector<Tag> tagallery::Tag::GetTags(const Gallery& gallery, std::optional<std::string> filter)
	{
		throw NotImplemented("Tag::GetTags");
		return std::vector<Tag>();
	}

	std::optional<Tag> tagallery::Tag::FindTagById(const Gallery& gallery, const size_t& id)
	{
		throw NotImplemented("Tag::FindTagById");
		return std::nullopt;
	}

	std::optional<Tag> tagallery::Tag::FindTagByName(const Gallery& gallery, const std::string& name)
	{
		throw NotImplemented("Tag::FindTagByName");
		return std::nullopt;
	}

	std::optional<Tag> tagallery::Tag::AddTag(const Gallery& gallery, const std::string& tagType, const std::string& name)
	{
		throw NotImplemented("Tag::AddTag");
		return std::nullopt;
	}

	Tag::Tag(const Gallery& owner, const size_t& index)
		: m_owner(owner)
		, m_index(index)
	{
		if (!m_owner.IsOpened())
		{
			throw InvalidGalleryRef();
		}
	}

	std::string tagallery::Tag::GetName() const
	{
		throw NotImplemented("Tag::GetName");
		return std::string();
	}

	void Tag::SetName(const std::string& name)
	{
		throw NotImplemented("Tag::SetName");
	}

	TagType tagallery::Tag::GetTagType() const
	{
		throw NotImplemented("Tag::GetTagType");
		return TagType(m_owner, INVALID_REF);
	}
	void Tag::SetTagType(const TagType& type) const
	{
		throw NotImplemented("Tag::SetTagType");
	}
}
