#ifndef GUARD_final_stu_h
#define GUARD_final_stu_h
#include <string>
#include <iostream>
#include <vector>
struct final_stu{
    std::string name;
    double final_grade;
};
bool compare(const final_stu&, const final_stu&);
std::istream& read(std::istream&, final_stu&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif