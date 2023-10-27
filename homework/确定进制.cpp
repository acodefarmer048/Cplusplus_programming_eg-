#include <iostream>

using std::cin; using std::cout;
using std::endl;

int binary_to_ten(int origin, int binary)
{
	int value=0;
	int weight=1;
	while (origin) {
		if ( (origin%10) >= binary) {
			value=-1;
			break;
		}
		value+=(origin%10)*weight;
		origin/=10;
		weight*=binary;
	}
	return value;
}

bool equation(int left, int right, int result, int binary)
{
	left=binary_to_ten(left, binary);
	right=binary_to_ten(right, binary);
	result=binary_to_ten(result, binary);
	if (left==-1 || right==-1 || result==-1 || left*right!=result)
		return false;
	else
		return true;
}

int main()
{
	int n;
	cin >> n;
	int left, right, result, binary;
	bool flag;
	for (int i=0; i!=n; ++i) {
		cin >> left >> right >> result;
	
		binary=2;
		flag=true;
		while (binary < 17) {
			if (equation(left, right, result, binary) ) {
				cout << binary << endl;
				flag=false;
				break;
			}
			++binary;
		}	
		if (flag) {
			cout << 0 << endl;
		}
	}
	return 0;
}
