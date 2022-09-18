#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> ignore_values;

std::vector<int> find_max(std::vector<int> input_data, std::vector<int> ignore_values)
{
    std::vector<int> max_indexes;

    auto find_max_lambda = [ignore_values](int l, int r)
    {
        if (std::find(ignore_values.begin(), ignore_values.end(), r) != ignore_values.end())
        {
            return false;
        }
        if (std::find(ignore_values.begin(), ignore_values.end(), l) != ignore_values.end())
        {
            return true;
        }
        return (l < r);
    };

    auto max = std::max_element(input_data.begin(), input_data.end(), find_max_lambda);
    for (int i = 0; i < input_data.size(); i++)
    {
        if (input_data[i] == *max)
        {
            max_indexes.push_back(i);
        }
    }
    return max_indexes;
}

std::vector<int> find_negative_indexes(std::vector<int> input_data, std::vector<int> ignore_values)
{
    std::vector<int> neg_indexes;

    for (int i = 0; i < input_data.size(); i++)
    {
        if (input_data[i] < 0 && std::find(ignore_values.begin(), ignore_values.end(), input_data[i]) == ignore_values.end())
        {
            neg_indexes.push_back(i);
        }
    }
    return neg_indexes;
}

void pos_part(std::vector<int> input_data)
{
    std::cout << "^\n";

    int max_value = *std::max_element(input_data.begin(), input_data.end());

    for (int j = max_value; j >= 0; j--)
    {
        auto max_indexes = find_max(input_data, ignore_values);
        if (input_data[max_indexes[0]] == j)
        {
            ignore_values.push_back(input_data[max_indexes[0]]);
        }
        if (j == 0)
        {
            std::cout << "+";
        }
        else
        {
            std::cout << "|";
        }

        for (int i = 0; i < input_data.size(); i++)
        {
            if (std::find(ignore_values.begin(), ignore_values.end(), input_data[i]) != ignore_values.end() || j == 0)
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}

void neg_part(std::vector<int> input_data)
{
    int min_value = *std::min_element(input_data.begin(), input_data.end());
    if (min_value >= 0)
    {
        return;
    }
    for (int j = 0; j > min_value; j--)
    {
        auto neg_indexes = find_negative_indexes(input_data, ignore_values);
        if (input_data[neg_indexes[0]] == j)
        {
            ignore_values.push_back(input_data[neg_indexes[0]]);
        }
        std::cout << "|";

        for (int i = 0; i < input_data.size(); i++)
        {
            if (std::find(ignore_values.begin(), ignore_values.end(), input_data[i]) == ignore_values.end())
            {
                std::cout << "#";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "v\n";
}

int main(int argc, char *argv[])
{
    std::vector<int> input_data{0, 3, 6, 7, 8, 7, 6, 3, 0, -3, -6, -7, -8, -7, -6, -3, 0};
    pos_part(input_data);
    neg_part(input_data);
}