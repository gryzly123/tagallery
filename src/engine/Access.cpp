#include "Access.hpp"

#include "SQLiteCpp/SQLiteCpp.h"

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
}
