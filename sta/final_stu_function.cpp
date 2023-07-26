#include "final_stu.h"
#include "median.h"
#include "final_grade.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <regex>
using std::vector; using std::string;
using std::istream; using std::domain_error;
/* bool compare(const final_stu&, const final_stu&);
std::istream& read(std::istream&, final_stu&);
std::istream& read_hw(std::istream&, vector<double>&); */

bool compare(const final_stu& x, const final_stu& y){
    return x.name< y.name;
}
istream& read(istream& is, final_stu& s){
    double midterm,final;
    is >> s.name >> midterm >> final;
    vector<double> hw;

    std::cout << std::endl <<"s_name: "<< s.name <<std::endl; 
    std::cout << std::endl <<"s_midterm and s_final: "<< midterm
              <<" "<< final << std::endl; 

    read_hw(is, hw);
    try{
        s.final_grade=final_grade(midterm, final, hw);
    }catch(domain_error e){
            std::cout << e.what();
        }//so that the error will not stop the output of calculated value
    return is;
}
istream& read_hw(istream& in, vector<double>& hw){
    if(in){
        hw.clear();

        double x;
        while(in>>x){
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}
