#include <iostream>

#include "Gallery.hpp"

#include "SQLiteCpp/SQLiteCpp.h"

namespace tagallery
{
	Gallery::Gallery(const std::string& path, const Access& accessType)
		: m_path(path)
		, m_access(accessType)
	{
		std::cout << "Opening " << m_path << "\n";

		int flags = SQLite::OPEN_READONLY;
		if (accessType != Access::ReadOnly)
		{
			flags = 0;
			if (accessType & Access::Create)
			{
				flags |= SQLite::OPEN_CREATE;
			}
			if (accessType & Access::MofifyTags)
			{
				flags |= SQLite::OPEN_READWRITE;
			}
		}
		
		try
		{
			m_db = std::make_unique< SQLite::Database >(m_path, flags);
		}
		catch (SQLite::Exception& e)
		{
			m_db = nullptr;
		}
	}

	Gallery::~Gallery()
	{
		std::cout << "Closing Gallery " << m_path << "\n";

		if (m_db)
		{
			m_db.reset();
		}
	}

}
