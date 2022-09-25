#include "rapidcsv.h"
#include "vector"

using item_t = std::vector<int>;
using designators_t = std::vector<std::string>;
using parts_t = std::vector<std::string>;
struct bom_item_t
{
    std::string part;
    std::vector<std::string> designators;
};

using bom_items_t = std::vector<bom_item_t>;

template <typename T>
std::vector<item_t> same_indexes(const std::vector<T>& fields)
{
    std::vector<int> used_index;
    std::vector<item_t> items;
    for (int i = 0; i < fields.size() - 1; i++)
    {
        if (std::find(used_index.begin(), used_index.end(), i) != used_index.end())
        {
            continue;
        }
        item_t item;
        item.push_back(i);
        for (int j = i + 1; j < fields.size(); j++)
        {
            if (fields[i] == fields[j])
            {
                item.push_back(j);
                used_index.push_back(j);
            }
        }
        if (item.size())
        {
            items.push_back(item);
        }
    }
    return items;
}

bom_items_t make_bom(const std::vector<item_t>& same_indexes, const designators_t& designators, const parts_t& parts)
{
    bom_items_t bom_items;
    for (int i = 0; i < same_indexes.size(); i++)
    {
        bom_item_t bom_item;
        int part_index = same_indexes[i][0];
        bom_item.part = parts[part_index];
        for (int j = 0; j < same_indexes[i].size(); j++)
        {
            bom_item.designators.push_back(designators[same_indexes[i][j]]);
        }
        bom_items.push_back(bom_item);
    }
    return bom_items;
}

void export_bom(const bom_items_t& bom_items, const std::string& path)
{
    std::ofstream output_file;
    output_file.open(path);
    output_file << "num,part,count,designators\n";
    int cnt = 1;
    for (auto bom_item : bom_items)
    {
        output_file << cnt++ << ',' << bom_item.part << ',' << bom_item.designators.size() << ',';
        for (auto designator : bom_item.designators)
        {
            output_file << designator << ' ';
        }
        output_file << '\n';
    }

    output_file.close();
}

int main(int argc, char *argv[])
{
    if (argc = !3)
    {
        std::cout << "Invalid arguments!\n";
        return -1;
    }
    std::vector<int> used_rows;
    rapidcsv::Document doc(argv[1]);
    auto num_row = doc.GetRowCount();
    std::string part_name = "part";
    parts_t parts = doc.GetColumn<std::string>(part_name);
    designators_t designators = doc.GetColumn<std::string>("designator");
    auto same_items = same_indexes(parts);
    auto bom = make_bom(same_items, designators, parts);
    export_bom(bom, argv[2]);
    return 0;
}