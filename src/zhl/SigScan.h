#pragma once

#include <vector>
#include <list>
#include <stddef.h>
#include <stdint.h>

class SigScan
{
public:
	class Match
	{
	public:
		Match(short b, short n) : address(0), begin(b), length(n) {}
		~Match() {}

		unsigned char *address;
		short begin;
		short length;
	};

	typedef void (*Callback)(SigScan *scan);

private:
	static unsigned char *s_pBase;
	static size_t s_iBaseLen;
	static unsigned char *s_pLastStartAddress;
	static unsigned char *s_pLastAddress;
	// "@<hex>" signatures name an address in the game binary (one fixed build, checked by
	// LC_UUID), so they are found by adding the image's load offset instead of scanning.
	static uintptr_t s_textVmAddr;
	static std::list<Match>& s_lastMatches() {
        static std::list<Match> s_lastMatches;
        return s_lastMatches;
	}

private:
	size_t m_iLength;
	unsigned char *m_sig;
	unsigned char *m_mask;
	std::list<Match> m_matches;

	bool m_bNoReturnSeek;
	bool m_bStartFromLastAddress;
	const char *m_alternative;  // For OR patterns: "pattern1|pattern2"

	unsigned char *m_pAddress;
	int m_dist;

	bool m_bAbsolute;   // "@<hex>": a fixed address in the game binary
	bool m_bAbsent;     // "@0": not present in this build
	uintptr_t m_vmAddr;
	int m_iAbsoluteLength;  // "@<hex>+<bytes>": the size of a no-op region

public:
	SigScan(const char *sig);
	~SigScan();

	bool Scan(Callback callback = NULL);

	void *GetAddress() const {return m_pAddress;}
	template <class T> T GetAddress() const
	{
		return reinterpret_cast<T>(m_pAddress);
	}
	int GetDistance() const {return m_dist;}

	bool IsAbsolute() const {return m_bAbsolute;}
	bool IsAbsent() const {return m_bAbsent;}

	int GetMatchCount() const {return m_matches.size();}
	const Match &GetMatch(int i = 0) const
	{
		auto it = m_matches.cbegin();
		for( ; i && it != m_matches.cend() ; ++it, --i);
		return *it;
	}

public:
	static void *GetBaseAddress() {return (void*)s_pBase;}
	static size_t GetBaseLength() {return s_iBaseLen;}
	static void Init();
#ifdef __ANDROID__
	// The port maps the game itself; Init() reads the code section from this image
	static void SetGameImage(const void *machHeader, intptr_t slide);
	// The image is the build of the game the definitions' addresses are for
	static bool IsKnownGame();
#endif
#ifdef ZHL_OFFLINE_SCAN
	static void InitFromBuffer(unsigned char *code, size_t len);  // code section read from disk
	static void SetTextVmAddress(uintptr_t vmaddr) {s_textVmAddr = vmaddr;}  // for "@" signatures
#endif
};
