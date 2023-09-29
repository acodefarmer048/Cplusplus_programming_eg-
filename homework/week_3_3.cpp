#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <numeric>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::accumulate; using std::sqrt;
using std::copy; using std::back_inserter;

vector<int> factor(int n)
{
	int srch_up=sqrt(n)+1;
	vector<int> fctrs;
	fctrs.push_back(1);
	for(int i=2; i<srch_up; ++i) {
		if (n%i==0) {
			fctrs.push_back(i);
			fctrs.push_back(n/i);
		}
	}
	return fctrs;
}
	
int check(int left)
{
	vector<int> fctr_lft=factor(left);
	int right = accumulate(fctr_lft.begin(), fctr_lft.end(),0);
	vector<int> fctr_rght=factor(right);
	if (accumulate(fctr_rght.begin(), fctr_rght.end(),0)==left && left < right)
		return right;
	return 0;
}
int main()
{
	int upmost;
	cin >> upmost;
	for (int i=220; i<upmost; ++i) {
		int j=check(i);
		if (j!=0 && j < upmost) {
			cout << i << " "
				<< j << endl;
		}
	}
	return 0;
}
