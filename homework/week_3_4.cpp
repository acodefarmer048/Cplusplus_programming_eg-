#include <iostream>
#include <vector>
#include <map>

using std::cin; using std::cout;
using std::vector; using std::map;
using std::endl;

int get_sum(int n)
{
	int total=0;
	while(n) {
		total+=n%10;
		n/=10;
	}
	return total;
}

		
void prnt_vc(vector<int> vc) {
	for (vector<int>::const_iterator it=vc.begin();
			it != vc.end(); ++it) {
		if (it != vc.begin())
			cout << ",";
		cout << *it;	
	}
	cout <<endl;
}
int main()
{
	map<int, vector<int> > sets;
	int beg,end,k;
	char delimiter;
	cin >> beg >> delimiter >> end >> delimiter >> k;

	int tmp;
	for (int i=beg+1; i<end; ++i) {
		tmp=get_sum(i);
		if (tmp%k==0) {
			sets[tmp/k].push_back(i);
		}
	}
	for(map<int, vector<int> >::const_iterator it=sets.begin();
			it != sets.end(); ++it) {
		prnt_vc(it->second);
	}
	return 0;
}
