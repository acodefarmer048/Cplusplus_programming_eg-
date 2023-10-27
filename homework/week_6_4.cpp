#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::next_permutation;

bool check(int (&players)[5])
{
	bool flag=true;
	if((players[1]==2 && players[0]==3) || 
		(players[1]!=2 && players[0]!=3))
		flag=false;
	
	if((players[1]==2 && players[4]==4) || 
		(players[1]!=2 && players[4]!=4))
		flag=false;

	if((players[3]==2 && players[2]==1) || 
		(players[3]!=2 && players[2]!=1))
		flag=false;

	if((players[2]==5 && players[3]==3) || 
		(players[2]!=5 && players[3]!=3))
		flag=false;

	if((players[4]==4 && players[0]==1) || 
		(players[4]!=4 && players[0]!=1))
		flag=false;
	
	return flag;
}
int main()
{
	int players[5]={1,2,3,4,5};
	do {
		bool flag=check(players);
		if (flag) 
			break;
	}while(next_permutation(players, players+5));
	for(int i=0; i!=5; ++i) {
		cout << players[i] << endl;
	}
	return 0;
}

