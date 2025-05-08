#include "hatch/parser.hpp"

#include <toml.hpp>

TOML11_DEFINE_CONVERSION_NON_INTRUSIVE(Hatch::MemoryPatchEntry, addr, value)

namespace Hatch {

void Parser::Parse(std::string& input_str) {
    auto source = toml::parse_str(input_str);

    hatch.version = CURRENT_VERSION;
    hatch.title_id = toml::find<u64>(source, "title_id");
    hatch.memory_patch =
        toml::find<std::vector<MemoryPatchEntry>>(source, "memory_patch");
}

} // namespace Hatch
