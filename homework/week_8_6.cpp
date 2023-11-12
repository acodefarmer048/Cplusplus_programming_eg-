#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl; using  std::vector;

int find_m(int k)
{
	vector<int> pulpils;
	for(int i=0; i!=k; ++i) {
		//0 means good;
		pulpils.push_back(0);
	}
	for(int i=0; i!=k; ++i) {
		//1 means bad;
		pulpils.push_back(1);
	}
	vector<int> backup=pulpils;
	int result, weight=1, left, current, steps;
	bool flag;
	while (true) {
		result=(k+1)*weight;
		left=2*k;
		current=0;
		flag=true;
		for(int i=0; i!=k; ++i) {
			steps=(result-1)%left;
			current=(current+steps)%left;
			if (pulpils[current]==0) {
				flag=false;
				break;
			}
			pulpils.erase(current+pulpils.begin());
			--left;
		}
		if (flag) {
			break;
		}
		pulpils=backup;

		result=(k+1)*weight+1;
		left=2*k;
		current=0;
		flag=true;
		for(int i=0; i!=k; ++i) {
			steps=(result-1)%left;
			current=(current+steps)%left;
			if (pulpils[current]==0) {
				flag=false;
				break;
			}
			pulpils.erase(current+pulpils.begin());
			--left;
		}
		if (flag) {
			break;
		}
		pulpils=backup;

		++weight;
	}
	return result;
}

int main()
{
	int k, m;
	while (true) {
		cin >> k;
		if (k==0) 
			break;
		else {
			m=find_m(k);
			cout << m << endl;
		}
	}
	return 0;
}	
