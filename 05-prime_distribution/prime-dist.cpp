#include <iostream>

bool is_prome(unsigned int num)
{
    if(num == 0 || num == 1)
    {
        return false;
    }
    for (unsigned int i = 2; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

struct user_data_t
{
    unsigned int column{20};
    unsigned int row{10};
    char prime_char{'X'};
    char no_prime_char{'-'};
};

user_data_t analize_user_data(int argc, char *argv[])
{
    return user_data_t();
}

int main(int argc, char *argv[])
{
    auto[column,row,prime_char,no_prime_char] =  analize_user_data(argc, argv);

    unsigned int counter = 1;

    for(unsigned int i = 0 ; i < row ; i++)
    {
        for (unsigned int j = 0 ; j < column ; j++)
        {
            if(is_prome(counter))
            {
                std::cout << prime_char;
            }
            else
            {
                std::cout << no_prime_char;
            }
            counter++;
        }
        std::cout <<'\n';
    }

    return 0;
}