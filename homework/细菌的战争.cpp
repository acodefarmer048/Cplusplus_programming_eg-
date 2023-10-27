#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main()
{
	const int capacity=1000000;
	int n;
	cin >> n;
	int bad, good;
	for (int i=0; i!=n; ++i) {
		cin >> bad >> good;
		int hours=0;
		while (bad > 0) {
			bad-=good;
			bad*=2;
			if (bad > capacity)
				bad=capacity;
			good=(int)(1.05*good);
			++hours;
		}
		cout << hours << endl;
	}
	return 0;
}
