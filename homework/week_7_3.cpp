#include <iostream>
#include <string>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::getline; using std::find_if;
using std::find;

bool is_colon(char c)
{
	return c==':';
}
bool check( string::iterator beg, string::iterator delim, string::iterator end )
{
	if (delim-beg==end-delim-1) {
		return false;
	}
	else {
		bool flag=true;
		string::iterator prev=delim, next;
		for(string::iterator it=beg;
			it!=delim; ++it) {
			next = find(prev+1, end, *it);
			if (next == end) {
				flag = false;
				break;
			}
			else {
				prev=next;
			}
		}
		
		return flag;
	}
}
		
		
		
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string origin;
	string::iterator delimiter;
	for(int i=0; i!=n; ++i) {
		getline(cin, origin);
		delimiter=find_if(origin.begin(), origin.end(), is_colon);
		if (check(origin.begin(), delimiter, origin.end())) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
		
		
	
