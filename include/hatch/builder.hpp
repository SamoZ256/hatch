#pragma once

#include <istream>
#include <ostream>

#include "hatch/common.hpp"

namespace Hatch {

constexpr u32 CURRENT_VERSION = 1;

struct BuildOptions {
    u32 version{CURRENT_VERSION};
};

class Builder {
  public:
    Builder() = default;
    ~Builder() = default;

    void Build(std::istream& input_stream, std::ostream& output_stream,
               const BuildOptions& options);
};

} // namespace Hatch
