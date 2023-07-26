#include <stdexcept>
#include <vector>
#include <algorithm>
#include "final_grade.h"
#include "median.h"
using std::domain_error; using std::vector;
using std::sort;
double final_grade(double midterm, double final, const vector<double>& hw){
    if(hw.size()==0){
        throw domain_error("student has done no homework");
    }
    return final_grade(midterm, final, median(hw));/*median will copy hw, which wouldnot contradict with the const quotation.*/
}
double final_grade(double midterm, double final, double homework){
    return 0.2*midterm+0.4*final+0.4*homework;
}

