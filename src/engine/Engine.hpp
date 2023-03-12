#pragma once

#include <memory>
#include <string>
#include <vector>

namespace tagallery
{
	class Gallery;
	struct Access;

	class Engine
	{
	public:
		Engine();
		~Engine();


		std::weak_ptr< Gallery > OpenGallery( std::string path, const Access& access);
		bool CloseGallery(std::weak_ptr<Gallery> gallery);

	private:
		std::vector<std::shared_ptr< Gallery >> m_galleries;
	};
}
