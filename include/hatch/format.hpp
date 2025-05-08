#pragma once

#include "hatch/common.hpp"

namespace Hatch {

constexpr u32 MAGIC = make_magic4('H', 'T', 'C', 'H');

struct Header {
    magic_t magic{MAGIC};
    u32 header_size{sizeof(Header)};
    u64 title_id;
    u32 code_patch_entry_count;
};

struct CodePatchEntry {
    u64 addr;
    u32 value;
};

} // namespace Hatch
