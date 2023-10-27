#include <iostream>
#include<string>
#include <map>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector; using std::map;

int main()
{
	int n;
	cin >> n;
	int book;
	string origin;
	map<char, vector<int> > books;
	for(int i=0; i!=n; ++i) {
		cin >> book >> origin;
		for(string::iterator it=origin.begin(); it!=origin.end(); ++it) {
			books[*it].push_back(book);
		}
	}
	map<char, vector<int> >::iterator note=books.begin();
	for(map<char, vector<int> >::iterator it=books.begin();
		it!=books.end(); ++it) {
		if((it->second).size() > (note->second).size()) {
			note=it;
		}
	}
	cout << note->first << endl << (note->second).size() << endl;
	for(vector<int>::iterator it=(note->second).begin();
		it!=(note->second).end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}
