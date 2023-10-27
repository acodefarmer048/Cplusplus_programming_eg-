#include <iostream>

using std::cin; using std::cout;
using std::endl;

bool is_equal(int (&array)[5])
{
	bool flag=true;
	for(int i=0; i!=4; ++i) {
		if(array[i]!=array[i+1]){
			flag=false;
			break;
		}
	}
	return flag;
}
		
int main()
{
	int k;
	int num[5];
	cin >> k;
	for(int i=0; i!=5; ++i) {
		cin >> num[i];
	}
	k*=100;
	int weight[5];
	bool is_found=false;
	for(int well=1; well <= k; ++well) {
		for (weight[0]=1; weight[0]!=k; ++weight[0]) {
			bool is_continue=false;
			for (int i=5; i>1; --i) {
				if ( (well-weight[(i%5)]) % num[(i+4)%5] !=0 ) {
					is_continue=true;
					break;
				}
				else
					weight[(i+4)%5]= (well-weight[(i%5)]) /num[(i+4)%5];
			}
			if (is_continue) 
				continue;
			
			if ((well-weight[1])%num[0]!=0) 
				continue;
			else if( (weight[0] == (well-weight[1])/num[0]) && (!is_equal(weight)) ) {
				is_found=true;
				cout << well;
				for (int i=0; i!=5; ++i) {
					cout << " " << weight[i];
				}
				return 0;
			}
		}
	}
	if(!is_found) {
		cout << "not found" << endl;
	}
	return 0;
}

