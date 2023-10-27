#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector; using std::map;
using std::getline; using std::max;

bool is_uppercase(char c)
{
	return c>='A' && c<='Z';
}
int main()
{
	map<char, int> dict;
	string str, tmp;
	for (int i=0; i!=4; ++i) {
		getline(cin, tmp);
		str+=tmp;
	}
	for (char c='A'; c<='Z'; ++c) {
		dict[c]=0;
	}
	for(string::iterator it=str.begin();
		it!=str.end(); ++it) {
		if (is_uppercase(*it)) {
			dict[*it]++;
		}
	}
	int height=0;
	vector<int> width;
	int count=26;
	while(count) {
		count=26;
		width.push_back(0);
		++height;
		cout << "line 37" << endl;
		for (char c='A'; c<='Z'; ++c) {
			if (dict[c] >= height)
				width[height-1]=c-'A';
			else 
				--count;
		}
	}
	--height;
	width.pop_back();
	for (int i=0; i!=height; ++i) {
		cout << "#";
		int letters=0;
	
		for (char c='A'; c<='A'+width[height-1-i]; ++c) {
			if (dict[c] < height-i) {
				cout << "  "; //two spaces;
			}
			else {
				cout << " *";
			}
		}
		cout << endl;
	}
	cout << "#";
	for (char c='A'; c<='Z'; ++c) {
		cout << " " << c ;
	}
	
	return 0;
}
