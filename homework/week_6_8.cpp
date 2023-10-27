#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::getline;
using std::string;

		
//beg must be the iterator of str
string::iterator find_delimiter(string& str, string::iterator beg, char delimiter) 
{
	string::iterator it=beg;
	while(*it!=delimiter && it!=str.end()) {
		++it;
	}
	return it;
}

void reverse_print(string::iterator beg, string::iterator end)
{
	for(string::iterator it=end-1;
		it >= beg; --it) {
		cout << *it;
	}
}

int main()
{
	string str;
	getline(cin, str);
	string::iterator it=str.begin(), delimiter=str.end();
	while(it!=str.end()) {
		if(delimiter!=str.end()) {
		//if true means that a delimiter exists, so it should move one step forward to avoid error
			cout << *delimiter;
			++it;
		}
		delimiter=find_delimiter(str, it, ' ');
		reverse_print(it, delimiter);
		it=delimiter;
	}
	return 0;
}
