#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::vector;

void print(vector<int> num)
{
	for(vector<int>::const_iterator it=num.begin();
		it!=num.end(); ++it) {
		cout << *it;
	}
	cout << endl;
}
vector<int> seven(int decimals)
{
	vector<int> result(3,0);
	int note=0;
	while(decimals) {
		result[2-note]=decimals%7;
		++note;
		decimals/=7;
	}
	return result;
}
vector<int> nine(int decimals)
{
	vector<int> result(3,0);
	int note=0;
	while(decimals) {
		result[2-note]=decimals%9;
		++note;
		decimals/=9;
	}
	return result;
}
bool rev_pres(int test)
{
	vector<int> sev=seven(test);
	vector<int> nin=nine(test);
	bool flag=true;
	for(int i=0; i<3; ++i) {
		if(sev[i]!=nin[2-i]) {
			flag=false;
			break;
		}
	}
	return flag;
}
		
int  main()
{
	int inf=81, sup=342;
	int flag;
	cin >> flag;
	for(int i=inf; i<=sup; ++i) {
		if(rev_pres(i)) {
			if (flag==1) {
				cout << i << endl;
			}
			else if (flag==2) {
				print(seven(i));
			}
			else if (flag==3) {
				print(nine(i));
			}
		}
	}
	return 0;
}
