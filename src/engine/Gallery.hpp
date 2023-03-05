#pragma once

#include <string>
#include <optional>
#include <unordered_map>
#include <vector>

namespace tagallery
{
	class TagType
	{
	public:
		static std::optional< TagType > FindTypeById(const size_t& id);
		static std::optional< TagType > FindTypeByName(const std::string name);
	private:
		const std::string m_typeName;
		const size_t m_index;
		

		static std::vector< TagType > s_types;
	};

	class Tag
	{
	public:

	private:
		const TagType& m_type;
		std::string m_name;
	};

	class Item
	{
	public:
		enum class Status
		{
			Exists,
			Missing,
		};

	private:
		const std::string m_path;
		Status m_status;
		std::vector< Tag > m_tags;
	};

	class Gallery
	{
	public:
		Gallery(std::string path);
		~Gallery();

	private:
		std::string m_path;
		std::unordered_map<std::string, Item> m_items;
	};
}
