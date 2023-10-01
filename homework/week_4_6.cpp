#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::sort;

int main()
{
	int r,n;
	vector<int> troops;
	while(true) {
		cin >> r >> n;
		if (r==-1)
			break;


		int coordinate;
		troops.clear();
		for (int i=0; i<n; ++i) {
			cin >> coordinate;
			troops.push_back(coordinate);
		}

		sort(troops.begin(), troops.end());

		int left=troops[0], soldier=troops[0], right, count=1;
		for(vector<int>::const_iterator it=troops.begin();
			it!=troops.end(); ++it) {

			right=*it;
			if(right-left>r && soldier==left ) {
				soldier=*(it-1);
			}
			if(right-soldier>r) {
				++count;
				left=*it;
				soldier=*it;
			}

		}
		cout << count << endl;
	}


	return 0;
}
