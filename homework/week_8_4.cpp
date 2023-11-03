#include <iostream>
#include <map>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::map; using std::getline;

bool is_uppercase(char c)
{
	return c>='A' && c<='Z';
}

char mapping_letter(char c)
{
	if (c=='A' || c=='B' || c=='C')
		return '2';
	else if (c=='D' || c=='E' || c=='F')
		return '3';
	else if (c=='G' || c=='H' || c=='I')
		return '4';
	else if (c=='J' || c=='K' || c=='L')
		return '5';
	else if (c=='M' || c=='N' || c=='O')
		return '6';
	else if (c=='P' || c=='R' || c=='S')
		return '7';
	else if (c=='T' || c=='U' || c=='V')
		return '8';
	else if (c=='W' || c=='X' || c=='Y')
		return '9';
	else
		return c; // Q and Z has no mapping;
}

string normalize(string& str)
{
	string mould;
	for( string::iterator it=str.begin();
		it != str.end(); ++it) {
		// formate exmaple: 310-1010
		if (mould.size() == 3)
			mould+='-';
		// omit surplus '-' in raw data
		if (*it=='-')
			continue;

		//append letters;
		if (is_uppercase(*it))
			mould+=mapping_letter(*it);
		else
			mould+=*it;
	}

	return mould;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	
	string raw;
	map<string, int> phonebook;
	for (int i=0; i!=n; ++i) {
		getline(cin, raw);
		++phonebook[normalize(raw)];
	}

	bool flag=true;
	for (map<string, int>::iterator it=phonebook.begin();
		it!=phonebook.end(); ++it) {
		if (it->second > 1) {
			cout << it->first << " " << it->second << endl;
			flag=false;
		}
	}
	if(flag) {
		cout << "No duplicates." << endl;
	}
	return 0;
}
