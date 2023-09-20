#include <iostream>
#include <ios>
#include <sstream>
#include <string>
using std::cin; using std::cout;
using std::streamsize; using std::string;
using std::stringstream; using std::getline;

int main()
{
	string input;
	double coordinate[2];
	char delimiter;
	getline(cin, input);
	stringstream ss(input);
	ss >> coordinate[0] >> delimiter >> coordinate[1];
	if (coordinate[0] > -1 && coordinate[0] < 1 && coordinate[1] > -1 && coordinate[1] < 1)
		cout << "yes";
	else
		cout << "no";
	return 0;
}
