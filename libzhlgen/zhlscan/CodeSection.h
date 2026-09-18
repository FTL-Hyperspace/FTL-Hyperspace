#pragma once

#include <string>
#include <vector>

// Reads the executable code of a binary on disk, laid out the way the OS
// loader maps it and the platform's SigScan::Init() scans it. Format is
// detected from the file. Nothing in here knows about ZHL.
bool ReadCodeSection(const std::string& path, std::vector<unsigned char>& code, std::string& error);
