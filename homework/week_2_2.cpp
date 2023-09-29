#include <iostream>
#include <vector>
using std::cin; using std::cout;
using std::vector;

int fib(int a)
{
	vector<int> fibs;
	fibs.push_back(1);
	fibs.push_back(1);
	int known=2;
	while (known < a) {
		fibs.push_back(fibs[known-1]+ fibs[known-2]);
		known+=1;
	}
	return fibs[known-1];
}

int main()
{
	int test;
	cin >> test;
	for (int i=0; i< test; ++i) {
		int a;
		cin >> a;
		int result=fib(a);
		cout << result << "\n";
	}
	return 0;
}


