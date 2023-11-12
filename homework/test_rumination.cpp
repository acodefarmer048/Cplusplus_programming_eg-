#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector; using std::getline;
using std::sort; 

bool compare(string& left, string& right)
{
	return left + right > right + left;
}

void print(vector<string>& vc)
{
	for (vector<string>::iterator it=vc.begin();
		it!=vc.end(); ++it) {
		cout << *it;
	}
}
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string tmp;
	vector<string> number;
	for (int i=0; i!=n; ++i) {
		getline(cin, tmp);
		number.push_back(tmp);
	}
	sort(number.begin(), number.end(), compare);
	print(number);

	return 0;
}
