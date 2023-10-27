#include <iostream>
#include <string>
#include <sstream>

using std::cout; using std::endl;
using std::cin; using std::string;
using std::stringstream; using std::getline;

int main()
{
	string origin;
	getline(cin, origin);
	stringstream ss(origin);
	cout << ss.rdbuf()->in_avail() << endl;

	getline(cin, origin);
	ss << origin;
	cout << ss.rdbuf()->in_avail() << endl;
	
	return 0;
}

