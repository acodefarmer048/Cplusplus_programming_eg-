#include <iostream>
#include <cmath>

using std::cin; using std::cout;
using std::endl; using std::sqrt;

bool is_prime(int num)
{
	if (num==2) return true;
	else if(num%2==0) return false;
	int upmost=sqrt(num)+1;
	for (int i=3; i<upmost; i=i+2) {
		if(num%i==0) {
			return false;
		}
	}
	return true;
}
	
int get_next_prime(int beg)
{
	while (true) {
		++beg;
		if (is_prime(beg)) {
			return beg;
		}
	}
}
	
bool is_intimate(int left, int right)
{
	int upmost= left<right ? right : left;
	for (int i=2; i <= upmost; i=get_next_prime(i)) {
		if ((left % i == 0 && right % i != 0) ||
			(right % i == 0 && left % i != 0) ){
			return false;

		}
	}
	return true;
}

int main()
{
	int left, right;
	char delimiter;
	cin >> left >> delimiter >> right;
	if (is_intimate(left, right)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
