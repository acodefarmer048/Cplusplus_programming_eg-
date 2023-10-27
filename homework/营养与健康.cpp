#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main()
{
	int tofu, milk, kelp, shrimp;
	cin >> tofu >> milk >> kelp >> shrimp;
	double calcium=tofu*110.0/100 + milk*120.0/100 
			+ kelp*2250.0/100 + shrimp*880/100;
	if (calcium < 600)
		cout << "UNDER" << endl;
	else if (calcium > 1000)
		cout << "OVER" << endl;
	else 
		cout << "FINE" << endl;
	return 0;
}
