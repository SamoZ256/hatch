#pragma once

#include "hatch/common.hpp"

namespace Hatch {

struct BuildOptions {};

class Builder {
  public:
    Builder() = default;
    ~Builder() = default;

    void Build(const std::string& input_str, std::ostream& output_stream,
               const BuildOptions& options);
};

} // namespace Hatch
