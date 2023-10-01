#include <iostream>
#include<cmath>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::round;
using std::abs; using std::vector;

int median(vector<int>& vc)
{
	return vc.size()%2==1? vc[vc.size()/2] 
				: (vc[vc.size()/2]+vc[vc.size()/2-1])/2;
}

int main()
{
	int num;
	cin >> num;
	int villages;
	for (int i=0; i<num; ++i){
		cin >> villages;
		int x;
		vector<int> farm;
		for (int j=0; j <villages; ++j) {
			cin >> x;
			farm.push_back(x);
		}
		int distance=0;
		int post_office=median(farm);
		for (int j=0; j<villages; ++j) {
			distance+=abs(farm[j]-post_office);
		}
		cout << distance << endl;
	}
	return 0;
}

	
		
