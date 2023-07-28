#include "average.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <ios>
using std::cout; using std::domain_error;
using std::vector; using std::accumulate;
double average(vector<double> vc){
	if(vc.size()==0)
		throw domain_error("average of an empty vector");
	return accumulate(vc.begin(), vc.end(), 0.0) / vc.size();
}
