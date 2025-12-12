#pragma once

#include <vector>
#include <list>
#include <string>
#include <cstddef>
#include "StringView.h"

class SigScan
{
public:
	class Match
	{
	public:
		constexpr Match(short b, short n) noexcept : begin(b), length(n) {}
		~Match() noexcept = default;

		unsigned char *address{nullptr};
		short begin;
		short length;
	};

	using Callback = void (*)(SigScan *);

private:
	static unsigned char *s_pBase;
	static size_t s_iBaseLen;
	static unsigned char *s_pLastStartAddress;
	static unsigned char *s_pLastAddress;
	static std::list<Match>& s_lastMatches() {
        static std::list<Match> s_lastMatches;
        return s_lastMatches;
	}

	size_t m_iLength;
	unsigned char *m_sig;
	unsigned char *m_mask;
	std::list<Match> m_matches;

	bool m_bNoReturnSeek;
	bool m_bStartFromLastAddress;
	bool m_bUseSymbolLookup;
	bool m_bHasFallback;
	bool m_bAlwaysFallback;
	bool m_bSymbolLookupSuccess;
	enum class SLType : std::uint8_t {
		BY_DEMANGLED,
		BY_NAME,
		BY_DEMANGLED_REGEX,
		BY_NAME_REGEX,
		BY_DEMANGLED_SIMPLE,
		BY_NAME_SIMPLE,
	} m_symbolLookupType;
	StringView m_symbolName;

	unsigned char *m_pAddress;
	int m_dist;

public:
	SigScan(const char *sig) noexcept;
	~SigScan() noexcept;

	bool Scan(Callback callback = nullptr);

	constexpr void *GetAddress() const noexcept {return m_pAddress;}
	template <class T> T GetAddress() const noexcept
	{
		return reinterpret_cast<T>(m_pAddress);
	}
	constexpr int GetDistance() const noexcept {return m_dist;}

	constexpr std::size_t GetMatchCount() const noexcept {return m_matches.size();}
	const Match &GetMatch(int i = 0) const noexcept
	{
		auto it = m_matches.cbegin();
		for( ; i && it != m_matches.cend() ; ++it, --i);
		return *it;
	}

	constexpr bool IsSymbolLookup() const noexcept {
		return m_bUseSymbolLookup;
	}

	constexpr bool IsSymbolLookupSuccess() const noexcept {
		return m_bSymbolLookupSuccess;
	}

	constexpr bool HasFallbackSig() const noexcept {
		return m_bHasFallback;
	}

	constexpr bool AlwaysFallback() const noexcept {
		return m_bAlwaysFallback;
	}

	const char* GetSymbolLookupType() const noexcept {
		switch (m_symbolLookupType) {
			case SLType::BY_NAME:
				return "name";
			case SLType::BY_DEMANGLED:
				return "demangled";
			case SLType::BY_NAME_REGEX:
				return "name regex";
			case SLType::BY_DEMANGLED_REGEX:
				return "demangled regex";
			case SLType::BY_NAME_SIMPLE:
				return "name simple";
			case SLType::BY_DEMANGLED_SIMPLE:
				return "demangled simple";
		}
		return "unknown";
	}

	static void *GetBaseAddress() noexcept {return s_pBase;}
	static size_t GetBaseLength() noexcept {return s_iBaseLen;}
	static void Init();
};
