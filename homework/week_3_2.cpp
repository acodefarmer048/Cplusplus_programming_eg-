#include <iostream>
#include <map>

using std::cin; using std::cout;
using std::endl; using std::map;

int main()
{
	int total, pot;
	cin >> total >> pot;
	if (total < pot)
		cout << 2 << endl;
	else
		if (total*2%pot==0)
			cout <<  total*2 / pot << endl;
		else
			cout <<  total*2 / pot+1 << endl;
	return 0;
}
	
