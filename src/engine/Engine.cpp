#include "Engine.hpp"
#include <iostream>
#include "Gallery.hpp"

namespace tagallery
{
	Engine::Engine()
	{
	}

	std::weak_ptr<Gallery> Engine::OpenGallery(std::string path)
	{
		auto gallery = std::make_shared<Gallery>( path );
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
