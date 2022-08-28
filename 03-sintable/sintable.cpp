#include <iostream>
#include <string.h>
#include <cmath>
bool is_number(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 3 || !is_number(argv[1]) || !is_number(argv[2]))
    {
        std::cout << "Invalid arguments.";
        return 1;
    }
    int num_samples = atoi(argv[1]);
    int num_bits = atoi(argv[2]);

    int max_value = (1 << num_bits-1) -1;
    double offset = 360.0 / num_samples;
    

    for(int i = 0 ; i < num_samples ; i++)
    {
        double current_degree = i*offset;
        int current_value = sin(current_degree*M_PI/180)*max_value;
        std::cout << current_value << '\n';
    }

    return 0;
}