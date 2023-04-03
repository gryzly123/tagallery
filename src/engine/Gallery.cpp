#include <iostream>
#include <filesystem>
#include <chrono>

#include "SQLiteCpp/SQLiteCpp.h"

#include "Gallery.hpp"
#include "Platform.hpp"
#include "Statements.hpp"

namespace fs = std::filesystem;

namespace tagallery
{
	int Access::ToSqliteFlags() const
	{
		int flags = SQLite::OPEN_READONLY;
		if (m_value != Access::ReadOnly)
		{
			flags = 0;
			if (m_value & Access::Create)
			{
				flags |= SQLite::OPEN_CREATE;
			}
			if (m_value & Access::MofifyTags)
			{
				flags |= SQLite::OPEN_READWRITE;
			}
		}
		return flags;
	}

	Gallery::Gallery(const std::string& path, const Access& accessType)
		: m_path(path)
		, m_access(accessType)
	{
		std::cout << "Opening " << m_path << "\n";

		//temporary
		//fs::remove(m_path);
		const bool dbExists = fs::exists(m_path);
		try
		{
			m_db = std::make_unique< SQLite::Database >(m_path, m_access.ToSqliteFlags());
			if (m_access & Access::Create && !dbExists)
			{
				BuildDatabase();
				PopulateDatabase(true);
			}
			else if (m_access & Access::MofifyTags)
			{
				PopulateDatabase(false);
			}
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

	void Gallery::BuildDatabase()
	{
		m_db->exec(STATEMENT_BUILD_SCHEMA);
	}

	void Gallery::PopulateDatabase(bool skipExistingCheck)
	{
		auto dir = m_path;
		auto dbName = dir.filename().string();
		dir.remove_filename();


		for (const auto& dirEntry : fs::recursive_directory_iterator(dir))
		{
			auto relPath = fs::relative(dirEntry.path(), dir);
			if (relPath.filename() == dbName)
			{
				continue;
			}

			if (!skipExistingCheck)
			{
				SQLite::Statement exists(*m_db, "SELECT id FROM item WHERE filename == ?");
				exists.bind(1, relPath.generic_string());
				if (exists.executeStep())
				{
					continue;
				}
			}

			auto dates = Platform::GetFileDates(dirEntry);

			SQLite::Statement addFile(*m_db, "INSERT INTO item(filename, dateAdded) VALUES(?,?)");
			addFile.bind(1, relPath.generic_string());
			addFile.bind(2, dates.value().created);
			addFile.exec();
		}
	}

	void Gallery::LoadDatabase()
	{
	}
}
