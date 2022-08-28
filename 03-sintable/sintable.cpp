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
    bool cosine = false;
    if (argc == 4 && argv[3][0] == 'c')
    {
        cosine = true;
    }

    int num_samples = atoi(argv[1]);
    int num_bits = atoi(argv[2]);

    int max_value = (1 << num_bits - 1) - 1;
    double interval = 2 * M_PI / num_samples;

    for (int i = 0; i < num_samples; i++)
    {
        double current_degree = i * interval;
        int current_value = sin(current_degree) * max_value;
        std::cout << current_value;
        if (cosine)
        {
            current_value = cos(current_degree) * max_value;
            std::cout <<'\t' << current_value;
        }
        std::cout << '\n';
    }

    return 0;
}