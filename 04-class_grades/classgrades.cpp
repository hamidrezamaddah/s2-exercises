#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <numeric>
#include <optional>
#include <sstream>
#include <utility>
#include <vector>

using grade_t = std::pair<std::string, double>;
using grades_t = std::vector<grade_t>;

void display_operations()
{
  std::cout << "\
#####################################\n\
#      Class Grades Management      #\n\
# --------------------------------- #\n\
#                                   #\n\
# 1. Display All Grades             #\n\
# 2. Show The Best Grade            #\n\
# 3. Calculate Class Average Grade  #\n\
# 4. Get List of Failed Students    #\n\
# 0. Exit                           #\n\
#####################################\n\
select command>";
}

std::optional<grades_t> analize_file(const std::string &path)
{
  std::ifstream grade_file;
  std::string line;
  grade_file.open(path);
  if (!grade_file)
  {
    return std::nullopt;
  }
  grades_t grades;
  while (std::getline(grade_file, line))
  {
    std::istringstream iss(line);
    double grade;
    std::string name;
    iss >> grade;
    iss >> name;
    if (name.empty())
    {
      continue;
    }
    grades.push_back({name, grade});
  }
  return grades;
}

void display_all_grades(const grades_t &grades)
{
  std::cout << "Class Grades:\n";
  for (auto &grade : grades)
  {
    std::cout << grade.second << '\t' << grade.first << '\n';
  }
}

void display_best_grade(const grades_t &grades)
{
  auto best = std::max_element(grades.begin(), grades.end(), [](const grade_t &l, const grade_t &r)
                               { return l.second < r.second; });
  std::cout << "The Best Grade is " << best->second << " from " << best->first
            << '\n';
}

auto get_average(const grades_t &grades)
{
  auto sum{0.0};
  for (auto &grade : grades)
  {
    sum += grade.second;
  }
  return sum / grades.size();
}

void display_average(const grades_t &grades)
{
  std::cout << "Class average grade is " << get_average(grades) << '\n';
}

void display_failed_grades(const grades_t &grades)
{
  std::cout << "Failed Students:\n";
  for (auto &grade : grades)
  {
    if (grade.second < 10)
    {
      std::cout << grade.second << '\t' << grade.first << '\n';
    }
  }
}

void run_commands(const grades_t &grades)
{
  while (true)
  {
    display_operations();
    int cmd;
    std::cin >> cmd;
    switch (cmd)
    {
    case 1:
      display_all_grades(grades);
      break;
    case 2:
      display_best_grade(grades);
      break;
    case 3:
      display_average(grades);
      break;
    case 4:
      display_failed_grades(grades);
      break;
    case 0:
      return;
      break;
    default:
      std::cout << "Invalid command!\n";
    }
  }
}

int main(int argc, char **argv)
{
  auto path = (argc == 2) ? argv[1] : "grades.txt";
  auto result = analize_file(path);
  if (!result)
  {
    std::cout << "File is not exist!\n";
    return 1;
  }
  auto &grades = result.value();
  if (grades.size() == 0)
  {
    std::cout << "File is empty!\n";
    return 0;
  }
  run_commands(grades);
  return 0;
}