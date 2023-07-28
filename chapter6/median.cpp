#include <stdexcept>
#include <vector>
#include <algorithm>
#include "median.h"
using std::domain_error; using std::vector;
using std::sort;

double median(vector<double> v){
    typedef vector<double>::size_type vec_sz;
    vec_sz size=v.size();
    if(size==0){
        throw domain_error("median of an empty vector");
        system("pause");
    }
    sort(v.begin(), v.end());
    vec_sz mid=size/2;
    return size%2==0? (v[mid]+v[mid-1])/2 : v[mid];
}