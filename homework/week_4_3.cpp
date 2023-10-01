#include <iostream>
#include <vector>
#include <cmath>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::min;

int get_cost(int hours, vector<int>& hrs_stairs, vector<int>& prc_stairs)
{
	int cost=0;
	cost+=min(hrs_stairs[0], hours) * prc_stairs[0];
	
	for(int i=1; i<hrs_stairs.size(); ++i) {
		if (hours>hrs_stairs[i] && i==0) {
			cost+=(hrs_stairs[i]-hrs_stairs[i-1])*prc_stairs[i];
		}
		else {
			cost+=(hours-hrs_stairs[i-1])*prc_stairs[i];
			break;
		}
	}
	if (hours>hrs_stairs.back()) {
		cost+=(hours-hrs_stairs.back())*prc_stairs.back();
	}
	return cost;
}

		


int main()
{
	int n,k,h;
	vector<int> hrs_stair, prc_stair;
	int tmp;
	cin >> n >> k >> h;
	//hours_stairs, namely the a[n]
	for (int i=0; i<n; ++i) {
		cin >> tmp;
		hrs_stair.push_back(tmp);
	}
	//price_stairs, namely the b[n]
	for (int i=0; i<n+1; ++i) {
		cin >> tmp;
		prc_stair.push_back(tmp);
	}

	int extra=h%k, average=h/k;
	int total=0;
	if (extra==0) {
		total+=get_cost(average, hrs_stair, prc_stair)*k;
		cout << total;
	}
	else {
		total+=get_cost(average, hrs_stair, prc_stair)*(k-extra);
		total+=get_cost(average+1, hrs_stair, prc_stair)*extra;
		cout << total;
	}

	return 0;
}
		
		
	

