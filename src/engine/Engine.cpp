#include "Engine.hpp"
#include <iostream>

namespace tagallery
{
	Engine::Engine( std::string path )
	{
		std::cout << "Opening " << path << "\n";
	}

	Engine::~Engine()
	{
		std::cout << "Closing engine\n";
	}

}
