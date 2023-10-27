#include <iostream>

using std::cin; using std::cout;
using std::endl; 

int calculate( int (&villages)[10000][2], int n, int area)
{
	cout << "area: " << area << endl;
	int beg_dis=0, end_dis=0;
//	for(int i=0; i!=(n+area-1)%n; ++i) {
//		beg_dis+=villages[i][1];
//	}
//	for(int i=n-1; i!=(n+area-2)%n; --i) {
//		end_dis+=villages[i][1];
//	}
//	// determine the final partition point where forward route reaches its end;
//	int pending=(n+area-2)%n;
//	int forward_decrease=0, backward_increase=0;
//	do {
//		forward_decrease=beg_dis*villages[(pending+1)%n][0];
//		backward_increase=(end_dis+villages[pending][1])*villages[pending][0];
//		if(forward_decrease > backward_increase )  {
//			end_dis+=villages[pending][1];
//			beg_dis-=villages[pending][1];
//			pending=(pending+n-1)%n;
//		}
//		cout << "forward_decrease : " << forward_decrease
//			<< " backward_increase : " << backward_increase << endl;
//	} while (forward_decrease > backward_increase );
//
//	int partition=(pending+1)%n;//partition is the real break point;
//	cout << "partition: " << partition << endl;
//	// beg has been reached while end has not;
	int beg=area, end=(n+area-1)%n;
	int total=0, result=-1;
	int partition=(area+1)%n;
	int forward, backward;
	while ( partition!=(area+n-1)%n) {
		cout << "partition: " << partition << endl;
		beg=area, end=(n+area-1)%n;
		beg_dis=0;
		end_dis=0;
		total=0;
		while( beg != partition || end != partition ) {
			forward=(beg_dis+villages[beg][1])*villages[(beg+1)%n][0];
			backward=(end_dis+villages[end][1])*villages[end][0];
			if( beg!=partition )  {
				cout << "forward: " << forward << endl;
				total+=forward;
				beg_dis+=villages[beg][1];
				beg=(beg+1)%n;
			}
			if ( end != partition) {
				cout << "backward: " << backward << endl;
				total+=backward;
				end_dis+=villages[end][1];
				end=(n+end-1)%n;
			}
		}
		cout << "total: " << total << endl;
		if ( result > total || result==-1) {
			result=total;
		}
		partition=(partition+1)%n;
	}
	// debug
	cout << " result: " << result << endl;
	return result;
}

int main()
{
	int n;
	int villages[10000][2];
	// demands for beer and the distance to the next village
	cin >> n;
	for(int i=0; i!=n; ++i) {
		cin >> villages[i][0] >> villages[i][1];
	}
	int cost=-1, result=0;
	for (int area=0; area!=n; ++area) {
		int tmp=calculate(villages, n, area);
		if (cost > tmp || cost==-1) {
			cost=tmp;
			result=area;
		}
	}

	cout << result << ',' << cost;
	return 0;
}
		
	
