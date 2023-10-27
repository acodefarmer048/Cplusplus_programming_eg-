#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector; using std::stringstream;
using std::sort;

bool is_digits(char c)
{
	if(c>='0' && c<='9')
		return true;
	else
		return false;
}
void get_num(string::iterator beg, string::iterator end, vector<int>& vc)
{
	string tmp(beg, end);
	stringstream ss(tmp);
	int num;
	ss >> num;
	vc.push_back(num);
}	
int main()
{
	string str;
	cin >> str;
	vector<int> number;
	string::iterator beg=str.end(), end=str.end();
	for(string::iterator it=str.begin();
		it!=str.end(); ++it) {
		if(is_digits(*it) && beg==str.end())
			beg=it;
		else if(!is_digits(*it) && beg!=str.end()) {
			end=it;
			get_num(beg, end, number);
			beg=str.end();
		}
		else if(it==str.end()-1 && beg!=str.end()) {
			end=str.end();
			get_num(beg, end, number);
			beg=str.end();
		}
	}
	
	if(number.size()==0) {
		cout << 0 << endl;
	}
	else {
		sort(number.begin(), number.end());
		for(int i=0; i!=number.size(); ++i) {
			cout << number[i];
			if (i!=number.size()-1) 
				cout << ",";
		}
	}
	return 0;
}
		
