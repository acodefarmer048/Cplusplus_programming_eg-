#include "average.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <ios>
using std::cout; using std::domain_error;
using std::vector;
double average(vector<double> vc){
    double sum=0;
    if(vc.size()==0)
        throw domain_error("average of an empty vector");
    for(vector<double>::const_iterator iter = vc.begin();
     iter != vc.end(); ++iter){
        sum+=*iter;
     }
     return sum/vc.size();
}