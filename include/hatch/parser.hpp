#pragma once

#include "hatch/format.hpp"

namespace Hatch {

class Parser {
  public:
    Parser() = default;
    ~Parser() = default;

    void Parse(std::istream& input_stream);

    // Getters
    u32 GetVersion() const { return version; }
    u64 GetTitleID() const { return title_id; }
    const std::vector<CodePatchEntry>& GetCodePatch() const {
        return code_patch;
    }

  private:
    u32 version{invalid<u32>()};
    u64 title_id{invalid<u64>()};
    std::vector<CodePatchEntry> code_patch;
};

} // namespace Hatch
