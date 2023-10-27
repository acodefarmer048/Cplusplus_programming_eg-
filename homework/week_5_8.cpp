#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string; using std::getline;
using std::stringstream;

void print_res(vector<int>& vc)
{
	for(vector<int>::reverse_iterator it=vc.rbegin();
		it != vc.rend(); ++it) {
		cout << *it;
	}
	cout << endl;
}
vector<int> bitadd(string one, string two)
{
	vector<int> result;
	
	string::reverse_iterator left=one.rbegin();
	string::reverse_iterator right=two.rbegin();
	int carry=0;
	while(left!=one.rend() && right!=two.rend()) {
		int lnum=*left-48, rnum=*right-48;
		if(lnum+rnum+carry>1) {
			result.push_back(lnum+rnum+carry-2);
			carry=1;
		}
		else {
			result.push_back(lnum+rnum+carry);
			carry=0;
		}
		++left;
		++right;
	}

	while (left!=one.rend()) {
		int lnum=*left-48;
		if(lnum+carry>1) {
			result.push_back(lnum+carry-2);
			carry=1;
		}
		else {
			result.push_back(lnum+carry);
			carry=0;
		}
		++left;
	}
			
	while (right!=two.rend()) {
		int rnum=*right-48;
		if(rnum+carry>1) {
			result.push_back(rnum+carry-2);
			carry=1;
		}
		else {
			result.push_back(rnum+carry);
			carry=0;
		}
		++right;
	}
	if(carry!=0) {
		result.push_back(carry);
		carry=0;
	}
	return result;
}
int main()
{
	string str;
	getline(cin, str);
	stringstream ss(str);
	int n;
	ss >> n;

	string left, right;
	vector<int> result;
	for (int i=0; i!=n; ++i) {
		getline(cin, left);
		getline(cin, right);
		result=bitadd(left, right);
		print_res(result);
	}
		
	return 0;
}
