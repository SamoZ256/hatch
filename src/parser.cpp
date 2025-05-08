#include "hatch/parser.hpp"
#include "hatch/format.hpp"

namespace Hatch {

void Parser::Parse(std::istream& input_stream) {
    StreamReader reader(input_stream);

    // Header
    const auto header = reader.Read<Header>();
    if (header.magic != MAGIC) {
        std::printf("Invalid magic 0x%08x\n", header.magic);
        return;
    }

    if (header.version != 1) {
        std::printf("Invalid version %u\n", header.version);
        return;
    }

    version = header.version;
    title_id = header.title_id;

    // Memory patch
    {
        const auto& section = header.sections[(u32)SectionType::MemoryPatch];
        const u32 entry_count = section.size / sizeof(MemoryPatchEntry);
        memory_patch.resize(entry_count);
        reader.ReadPtr(memory_patch.data(), entry_count);
    }
}

} // namespace Hatch
