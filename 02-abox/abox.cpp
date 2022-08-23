#include <iostream>
#include <string.h>

bool is_number(char* str)
{
    for(int i = 0 ; i < strlen(str); i++)
    {
        if(!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
 if(argc < 3 || !is_number(argv[1]) || !is_number(argv[2]))
 {
    std::cout << "Invalid arguments.";
    return 1;
 }
 int h = atoi(argv[1]);
 int w = atoi(argv[2]);
 char draw = '*';
 bool wire = false;
 if(argc >= 4)
 {
    if(strstr(argv[3],"wire"))
    {
        wire = true;
    }
    else
    {
        draw = argv[3][0];
    }
 }

 for(int i = 0 ; i < h ; i++)
 {
    for(int j = 0 ; j < w ; j++)
    {
        if(i != 0 && i != h-1 && j != 0 && j != w-1)
        {
            std::cout << " ";
        }
        else
        {
            if(wire)
            {
                if(( i == 0 && j == 0) || ( i == 0 && j == w-1) || ( i == h-1 && j == 0) || ( i == h-1 && j == w-1) )
                {
                    std::cout << "+";
                }
                else if(i == 0 || i == h-1)
                {
                    std::cout << "-";
                }
                else
                {
                    std::cout << "|";
                }
            }
            else
            {
                std::cout << draw;
            }
        }
    }
    std::cout << "\n";
 }
 return 0;
}