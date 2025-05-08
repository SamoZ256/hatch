#include <fstream>
#include <sstream>
#include <string>

#include "hatch/hatch.hpp"

int main(int argc, char* argv[]) {
    std::string input_filename;
    std::string output_filename;

    // TODO: use a proper argument parser
    // TODO: allow version overriding
    if (argc != 3) {
        std::printf("Expected 2 arguments, got %i\n", argc - 1);
        return -1;
    }
    input_filename = argv[1];
    output_filename = argv[2];

    // TODO: verify filenames

    // Input
    std::ifstream input_stream(input_filename, std::ios::in);
    std::ostringstream oss;
    oss << input_stream.rdbuf();
    std::string input_str = oss.str();

    // Output
    // TODO: make intermediate directories
    std::ofstream output_stream(output_filename,
                                std::ios::out | std::ios::binary);

    // Parse
    Hatch::Parser parser;
    parser.Parse(input_str);

    // Serialize
    Hatch::Serializer serializer(parser.GetHatch());
    serializer.Serialize(output_stream);

    // Cleanup
    output_stream.close();
    input_stream.close();

    return 0;
}
