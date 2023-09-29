#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::istream;

class quadrilateral {
public:
	istream& read_dots(istream& cin)
	{
		for (int i=0; i<4; ++i) {
			for (int j=0; j<2; ++j) {
				cin >>dots[i][j];
			}
		}
		return cin;
	}
	bool concavity()
	{
		int ipsilateral[4];
		for (int i=0; i<4; ++i) {
			int tmp=outer_product(i%4,(i+1)%4,(i+2)%4);
			if (tmp>0)
				ipsilateral[i]=1;
			else if (tmp<0)
				ipsilateral[i]=-1;
			else
				ipsilateral[i]=0;
		}
		for (int i=1; i<4; ++i) {
			if (ipsilateral[i]!=ipsilateral[0])
			return 0;
		}
		return 1;
	}
			
private:
	int dots[4][2];
	int outer_product(int ref_1,int ref_2,int ref_3)
	{
		int edges[2][2];
		edges[0][0]=dots[ref_2][0]-dots[ref_1][0];
		edges[0][1]=dots[ref_2][1]-dots[ref_1][1];
		edges[1][0]=dots[ref_3][0]-dots[ref_1][0];
		edges[1][1]=dots[ref_3][1]-dots[ref_1][1];
		return edges[0][0]*edges[1][1]-edges[1][0]*edges[0][1];
	}

};

int main() {
	quadrilateral one;
	while(one.read_dots(cin)) {
		if (one.concavity())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
		
	return 0;
}

	
