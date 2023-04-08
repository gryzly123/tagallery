#pragma once

#include <memory>

namespace tagallery
{
	struct Access
	{
		constexpr static uint8_t ReadOnly = 0;    // only read and query the database
		constexpr static uint8_t ModifyTags = 1;  // can edit the database but cannot touch the files. Can react to directory changes
		constexpr static uint8_t ModifyFiles = 2; // can edit the database and files (rename, delete)
		constexpr static uint8_t Create = 4;      // can create the database if it doesn't exist

		uint8_t m_value;

		constexpr Access()
			: m_value(ReadOnly)
		{
		}
		
		constexpr Access(const uint8_t& value)
			: m_value(value)
		{
		}

		constexpr operator uint8_t() const
		{
			return m_value;
		}

		int ToSqliteFlags() const;

		bool CanModifyTags() const { return m_value & ModifyTags; }
		bool CanModifyFiles() const { return m_value & ModifyFiles; }
	};
}
