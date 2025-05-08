#pragma once

#include "hatch/common.hpp"

namespace Hatch {

constexpr u32 CURRENT_VERSION = 1;

struct BuildOptions {};

class Builder {
  public:
    Builder() = default;
    ~Builder() = default;

    void Build(const std::string& input_str, std::ostream& output_stream,
               const BuildOptions& options);
};

} // namespace Hatch
