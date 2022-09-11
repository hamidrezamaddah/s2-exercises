#include <iostream>
#include "bit_funcs.h"
#include "base64_encode.hpp"

int main(int argc, char* argv[])
{
    base64_encode_t base64_encode;
    base64_encode.add("Hello World!!");
    std::cout << "encode to base64: " << base64_encode.encode();
    return 0;
}