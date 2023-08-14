#include <iostream>
#include <string>
#include <vector>
#include "picture.h"

using std::cin; using std::cout;
using std::string; using std::vector;

int main()
{
	vector<string> pic;
	string x;
	while(cin >> x)
		pic.push_back(x);
	Picture p(pic);
	Picture framed=frame(p);
	Picture combined=hcat(framed, p);
	Picture lastversion = vcat(combined, p);
	cout << lastversion;
	return 0;
}
