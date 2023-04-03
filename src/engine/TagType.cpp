#include "Gallery.hpp"
#include "TagType.hpp"

namespace tagallery
{
	std::vector<TagType> TagType::GetTypes(const Gallery& gallery, std::optional<std::string> filter)
	{
		throw NotImplemented("TagType::GetTypes");
		return std::vector<TagType>();
	}

	std::optional<TagType> TagType::FindTypeById(const Gallery& gallery, const size_t& id)
	{
		throw NotImplemented("TagType::FindTypeById");
		return std::nullopt;
	}

	std::optional<TagType> TagType::FindTypeByName(const Gallery& gallery, const std::string name)
	{
		throw NotImplemented("TagType::FindTypeByName");
		return std::nullopt;
	}

	std::optional<TagType> TagType::AddTagType(const Gallery& gallery, const std::string typeName)
	{
		throw NotImplemented("TagType::AddTagType");
		return std::nullopt;
	}

	TagType::TagType(const Gallery& owner, const size_t& index)
		: m_owner(owner)
		, m_index(index)
	{
		if (!m_owner.IsOpened())
		{
			throw InvalidGalleryRef();
		}
	}

	std::string TagType::GetName() const
	{
		throw NotImplemented("TagType::GetName");
		return std::string();
	}

	void TagType::SetName(const std::string& name)
	{
		throw NotImplemented("TagType::SetName");
	}
}
