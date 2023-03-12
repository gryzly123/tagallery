#include <iostream>
#include <filesystem>

#include "Engine.hpp"
#include "Gallery.hpp"

namespace tagallery
{
	Engine::Engine()
	{
	}

	std::weak_ptr<Gallery> Engine::OpenGallery(std::string path, const Access& access)
	{
		std::filesystem::path dbPath = std::filesystem::absolute(path);
		if (!std::filesystem::is_directory(dbPath))
		{
			dbPath = dbPath.parent_path();
		}
		dbPath /= "tagallery.db";

		auto gallery = std::make_shared<Gallery>( dbPath.string(), access);
		m_galleries.push_back(gallery);
		return gallery;
	}

	bool Engine::CloseGallery(std::weak_ptr<Gallery> gallery)
	{
		return false;
	}

	

	Engine::~Engine()
	{
	}

}
