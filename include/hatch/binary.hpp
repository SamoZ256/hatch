#pragma once

#include "hatch/format.hpp"

namespace Hatch {

class Serializer {
  public:
    Serializer(const Hatch& hatch_) : hatch{hatch_} {}
    ~Serializer() = default;

    void Serialize(std::ostream& output_stream);

  private:
    const Hatch& hatch;
};

class Deserializer {
  public:
    Deserializer() = default;
    ~Deserializer() = default;

    void Deserialize(std::istream& input_stream);

    // Getters
    const Hatch& GetHatch() const { return hatch; }

  private:
    Hatch hatch;
};

} // namespace Hatch
