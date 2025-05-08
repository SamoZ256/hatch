#include "hatch/builder.hpp"

#include <toml.hpp>

#include "hatch/format.hpp"

TOML11_DEFINE_CONVERSION_NON_INTRUSIVE(Hatch::CodePatchEntry, addr, value)

namespace Hatch {

void Builder::Build(const std::string& input_str, std::ostream& output_stream,
                    const BuildOptions& options) {
    auto source = toml::parse_str(input_str);
    StreamWriter writer(output_stream);

    Header header{};

    // Parse

    // Title ID
    header.title_id = toml::find<u64>(source, "title_id");

    // Code patches
    auto code_patch =
        toml::find<std::vector<CodePatchEntry>>(source, "code_patch");
    header.sections[(u32)SectionType::CodePatch] = {
        static_cast<u32>(sizeof(Header)),
        static_cast<u32>(code_patch.size() * sizeof(CodePatchEntry))};

    // Write

    // Header
    writer.Write(header);

    // Code patch
    for (const auto& entry : code_patch)
        writer.Write(entry);
}

} // namespace Hatch
