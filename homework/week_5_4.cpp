#include <iostream>
#include <cmath>

using std::cin; using std::cout;
using std::endl; using std::max;

int main()
{
	int n;
	cin >> n;
	do {
		int current, previous, plat_len=0, max_len=0;
		for(int i=0; i<n; ++i) {
			cin >> current;
			if(i==0 || previous==current) {
				++plat_len;
			}
			else {
				if (plat_len>max_len) {
					max_len=plat_len;
				}
				plat_len=1;
			}
			previous=current;
		}
		cout << max(max_len, plat_len) << endl;
		cin >> n;
	} while(n!=0);
	return 0;
}

