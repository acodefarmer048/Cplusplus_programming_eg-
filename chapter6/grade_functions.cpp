#include <stdexcept>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "average.h"
#include "Student_info.h"
using std::domain_error; using std::vector;
using std::sort;
double grade(double midterm, double final, const vector<double>& hw){
    if(hw.size()==0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}
double grade(double midterm, double final, double homework){
    return 0.2*midterm+0.4*final+0.4*homework;
}
double grade(const Student_info& s){
    return grade(s.midterm, s.final, s.homework);
}
bool fgrade(const Student_info& s){
    return grade(s) < 60;
}

