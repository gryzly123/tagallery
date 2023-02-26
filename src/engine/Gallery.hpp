#pragma once

#include <string>
#include <unordered_map>

namespace tagallery
{
	class Gallery
	{
	public:
		Gallery(std::string path);
		~Gallery();

	private:
		std::string m_path;
	};
}
