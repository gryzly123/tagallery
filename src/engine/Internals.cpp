#include "Internals.hpp"

#include "SQLiteCpp/SQLiteCpp.h"

namespace tagallery
{
	void ThrowIfNotDone(SQLite::Statement& s)
	{
		if (s.executeStep())
		{
			throw MultipleItemsFound();
		}
	}
}
