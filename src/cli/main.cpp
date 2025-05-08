#include <fstream>
#include <string>

#include "hatch/hatch.hpp"

int main(int argc, char* argv[]) {
    std::string input_filename;
    std::string output_filename;
    Hatch::BuildOptions options{};

    // TODO: use a proper argument parser
    // TODO: allow version overriding
    if (argc != 3) {
        std::printf("Expected 2 arguments, got %i\n", argc - 1);
        return -1;
    }
    input_filename = argv[1];
    output_filename = argv[2];

    // TODO: verify filenames

    std::ifstream input_stream(input_filename);
    std::ofstream output_stream(output_filename);

    Hatch::Builder builder;
    builder.Build(input_stream, output_stream, options);

    output_stream.close();
    input_stream.close();

    return 0;
}
