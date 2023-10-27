#include <iostream>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::string;

int main()
{
	string num;
	cin >> num;
	size_t s_len=num.size();
	bool flag=true;
	for(int i=0; i<=s_len/2; ++i) {
		if (num[i] != num[s_len-1-i]) {
			cout << "no" << endl;
			flag=false;
			break;
		}
	}
	if (flag) {
		cout << "yes" << endl;
	}
	return 0;
}
