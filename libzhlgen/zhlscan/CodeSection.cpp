// Each branch mirrors the matching SigScan::Init(): Mach-O scans __TEXT,__text,
// PE scans .text for its full VirtualSize, Linux scans the whole first
// executable PT_LOAD segment. Memory beyond the file-backed bytes is zero,
// as the loader leaves it.

#include "CodeSection.h"

#include <LIEF/ELF.hpp>
#include <LIEF/MachO.hpp>
#include <LIEF/PE.hpp>

namespace {

void CopyMapped(LIEF::span<const uint8_t> content, uint64_t mappedSize, std::vector<unsigned char>& code)
{
    code.assign(content.begin(), content.end());
    code.resize(mappedSize, 0);
}

bool ReadMachO(const std::string& path, std::vector<unsigned char>& code, std::string& error)
{
    std::unique_ptr<LIEF::MachO::FatBinary> fat = LIEF::MachO::Parser::parse(path);
    const LIEF::MachO::Binary* binary = fat ? fat->at(0) : nullptr;
    const LIEF::MachO::Section* text = binary ? binary->get_section("__TEXT", "__text") : nullptr;
    if (!text)
    {
        error = "no __TEXT,__text section";
        return false;
    }
    CopyMapped(text->content(), text->size(), code);
    return true;
}

bool ReadPE(const std::string& path, std::vector<unsigned char>& code, std::string& error)
{
    std::unique_ptr<LIEF::PE::Binary> binary = LIEF::PE::Parser::parse(path);
    const LIEF::PE::Section* text = binary ? binary->get_section(".text") : nullptr;
    if (!text)
    {
        error = "no .text section";
        return false;
    }
    CopyMapped(text->content(), text->virtual_size(), code);
    return true;
}

bool ReadElf(const std::string& path, std::vector<unsigned char>& code, std::string& error)
{
    std::unique_ptr<LIEF::ELF::Binary> binary = LIEF::ELF::Parser::parse(path);
    if (binary)
    {
        for (const LIEF::ELF::Segment& segment : binary->segments())
        {
            if (segment.type() == LIEF::ELF::Segment::TYPE::LOAD && segment.has(LIEF::ELF::Segment::FLAGS::X))
            {
                CopyMapped(segment.content(), segment.virtual_size(), code);
                return true;
            }
        }
    }
    error = "no executable PT_LOAD segment";
    return false;
}

} // namespace

bool ReadCodeSection(const std::string& path, std::vector<unsigned char>& code, std::string& error)
{
    if (LIEF::MachO::is_macho(path))
    {
        return ReadMachO(path, code, error);
    }
    if (LIEF::PE::is_pe(path))
    {
        return ReadPE(path, code, error);
    }
    if (LIEF::ELF::is_elf(path))
    {
        return ReadElf(path, code, error);
    }
    error = "not a Mach-O, PE or ELF binary";
    return false;
}
