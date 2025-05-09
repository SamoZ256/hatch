#pragma once

#include "hatch/common.hpp"

namespace Hatch {

constexpr u32 MAGIC = make_magic4('H', 'T', 'C', 'H');

constexpr u32 CURRENT_VERSION = 1;

struct Section {
    u64 offset;
    u64 size;
};

enum class SectionType {
    MemoryPatch = 0,

    Count,
};

struct Header {
    magic_t magic{MAGIC};
    u32 version{CURRENT_VERSION};
    u32 header_size{sizeof(Header)};
    Section sections[(u32)SectionType::Count];
};

struct MemoryPatchEntry {
    u64 addr;
    u32 value;
};

class Hatch {
  public:
    friend class Serializer;
    friend class Deserializer;
    friend class Parser;

    Hatch() = default;
    ~Hatch() = default;

    // Getters
    u32 GetVersion() const { return version; }
    const std::vector<MemoryPatchEntry>& GetMemoryPatch() const {
        return memory_patch;
    }

  private:
    u32 version{invalid<u32>()};
    std::vector<MemoryPatchEntry> memory_patch;
};

} // namespace Hatch
