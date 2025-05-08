#pragma once

#include "hatch/format.hpp"

namespace Hatch {

class Parser {
  public:
    Parser() = default;
    ~Parser() = default;

    void Parse(std::string& input_str);

    // Getters
    const Hatch& GetHatch() const { return hatch; }

  private:
    Hatch hatch;
};

} // namespace Hatch
