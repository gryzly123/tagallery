#include "Gallery.hpp"
#include <iostream>

namespace tagallery
{
	Gallery::Gallery( std::string path )
		: m_path(path)
	{
		std::cout << "Opening " << path << "\n";
	}

	Gallery::~Gallery()
	{
		std::cout << "Closing Gallery\n";
	}

}
