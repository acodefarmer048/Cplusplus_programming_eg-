#include <iostream>
#include <map>

using std::cin; using std::cout;
using std::endl; using std::map;

int main()
{
	int num, x;
	cin >> num;
	map<int ,int> array;

	for (int i=0; i<num; ++i) {
		cin >> x;
		++array[x];
	}

	for (int i=1; i<=num; ++i) {
		if (array[i]==0)
			cout << i << endl;
	}
	return 0;
}
