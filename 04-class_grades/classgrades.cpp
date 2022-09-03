#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <numeric>
#include <optional>
#include <sstream>
#include <utility>
#include <vector>

struct student_t
{
  std::string name;
  double grade;
};

using students_t = std::vector<student_t>;

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

std::optional<students_t> analize_file(const std::string &path)
{
  std::ifstream grade_file;
  std::string line;
  grade_file.open(path);
  if (!grade_file)
  {
    return std::nullopt;
  }
  students_t students;
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
    students.push_back({name, grade});
  }
  return students;
}

void display_all_grades(const students_t &students)
{
  std::cout << "Class Grades:\n";
  for (auto &student : students)
  {
    std::cout << student.grade << '\t' << student.name << '\n';
  }
}

void display_best_grade(const students_t &students)
{
  auto best = std::max_element(students.begin(), students.end(), [](const student_t &l, const student_t &r)
                               { return l.grade < r.grade; });
  std::cout << "The Best Grade is " << best->grade << " from " << best->name
            << '\n';
}

auto get_average(const students_t &students)
{
  auto sum{0.0};
  for (auto &student : students)
  {
    sum += student.grade;
  }
  return sum / students.size();
}

void display_average(const students_t &students)
{
  std::cout << "Class average grade is " << get_average(students) << '\n';
}

void display_failed_grades(const students_t &students)
{
  std::cout << "Failed Students:\n";
  for (auto &student : students)
  {
    if (student.grade < 10)
    {
      std::cout << student.grade << '\t' << student.name << '\n';
    }
  }
}

void run_commands(const students_t &students)
{
  while (true)
  {
    display_operations();
    int cmd;
    std::cin >> cmd;
    switch (cmd)
    {
    case 1:
      display_all_grades(students);
      break;
    case 2:
      display_best_grade(students);
      break;
    case 3:
      display_average(students);
      break;
    case 4:
      display_failed_grades(students);
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
  auto &students = result.value();
  if (students.size() == 0)
  {
    std::cout << "File is empty!\n";
    return 0;
  }
  run_commands(students);
  return 0;
}