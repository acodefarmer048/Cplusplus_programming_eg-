#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector; using std::stringstream;
using std::getline; using std::sort;
using std::unique;

int main()
{
	string tmp;
	int element;
	char delimiter;
	stringstream ss;
	vector<int> one, two;

	getline(cin, tmp);
	ss << tmp;
	while (ss >> element) {
		one.push_back(element);
		if (ss) 
			ss >> delimiter;
	}
	ss.clear();
			
	getline(cin, tmp);
	ss << tmp;
	while (ss >> element) {
		two.push_back(element);
		if (ss) 
			ss >> delimiter;
	}

	sort(one.begin(), one.end());
	one.erase(unique(one.begin(), one.end()), one.end());
	sort(two.begin(), two.end());
	two.erase(unique(two.begin(), two.end()), two.end());

	vector<int>::iterator left=one.begin();
	vector<int>::iterator right=two.begin();
	vector<int> crossed;
	//we only need to find the crossed elements; therefore no need to access all ints in both 
	//left and right
	while (left != one.end() && right != two.end()) {
		if (*left==*right) {
			crossed.push_back(*left);
			++left;
			++right;
		}
		else if (*left > *right) 
			++right;
		else
			++left;
	}
	if (crossed.size()==0) {
		cout << "NULL";
	}
	else {
		for (vector<int>::iterator it=crossed.begin(); 
			it!=crossed.end(); ++it) {
			cout << *it << ',';
		}
		cout << "\b";
	}
	return 0;
}
