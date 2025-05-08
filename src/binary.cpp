#include "hatch/binary.hpp"

namespace Hatch {

void Serializer::Serialize(std::ostream& output_stream) {
    StreamWriter writer(output_stream);

    // Header
    Header header{
        .version = hatch.version,
        .title_id = hatch.title_id,
        .sections =
            {
                {static_cast<u32>(sizeof(Header)),
                 static_cast<u32>(hatch.memory_patch.size() *
                                  sizeof(MemoryPatchEntry))},
            },
    };

    // Write
    writer.Write(header);
    writer.WritePtr(hatch.memory_patch.data(), hatch.memory_patch.size());
}

void Deserializer::Deserialize(std::istream& input_stream) {
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

    hatch.version = (header.version);
    hatch.title_id = header.title_id;

    // Memory patch
    {
        const auto& section = header.sections[(u32)SectionType::MemoryPatch];
        const u32 entry_count = section.size / sizeof(MemoryPatchEntry);
        hatch.memory_patch.resize(entry_count);
        reader.ReadPtr(hatch.memory_patch.data(), entry_count);
    }
}

} // namespace Hatch
