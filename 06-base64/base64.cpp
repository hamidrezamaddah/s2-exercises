#include <iostream>
#include "base64_encode.hpp"
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 4 || argv[1] != static_cast<std::string>("enc"))
    {
        std::cout << "Invalid arguments!\n";
    }
    base64_encode_t base64_encode;
    std::ifstream input(argv[2], std::ios::binary);
    std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(input), {});
    base64_encode.set_data(&buffer);
    std::ofstream output_file;
    output_file.open(argv[3]);
    output_file << base64_encode.convert();
    output_file.close();
    return 0;
}