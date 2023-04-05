#pragma once

#include <memory>
#include <stdexcept>

namespace SQLite
{
	class Statement;
}

namespace tagallery
{
	// types
	class dbIdx
	{
	public:
		constexpr dbIdx(int32_t value) : m_value(value) {}
		constexpr dbIdx(int64_t value) : m_value(value) {}
		constexpr dbIdx(uint32_t value) : m_value(value) {}
		constexpr dbIdx(uint64_t value) : m_value(value) {}
		constexpr dbIdx(const dbIdx& other) : m_value(other.m_value) {}
		constexpr operator int64_t() const { return static_cast<uint64_t>(m_value); }

	private:
		uint64_t m_value;
	};

	// constants
	const dbIdx INVALID_REF = std::numeric_limits<int64_t>::max();

	// exceptions
	class NotImplemented : public std::logic_error
	{
	public:
		NotImplemented(const std::string& methodName = "")
			: std::logic_error("Method " + methodName + " not implemented")
		{
		};
	};

	class InvalidGalleryRef : public std::logic_error
	{
	public:
		InvalidGalleryRef() : std::logic_error("Gallery reference was not valid")
		{
		};
	};

	class MultipleItemsFound : public std::logic_error
	{
	public:
		MultipleItemsFound() : std::logic_error("Query returned more rows than expected - database is not valid.")
		{
		};
	};

	// helper methods
	void ThrowIfNotDone(SQLite::Statement& s);
}