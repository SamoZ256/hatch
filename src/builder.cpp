#include "hatch/builder.hpp"

namespace Hatch {

void Builder::Build(std::istream& input_stream, std::ostream& output_stream,
                    const BuildOptions& options) {
    // HACK
    output_stream << "HELLO";
}

} // namespace Hatch
