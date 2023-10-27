#include <iostream>

using std::cin; using std::cout;
using std::endl;

bool is_border(int next_i, int next_j, int row, int column, int (&matrix)[100][100])
{
	bool flag=false;
	if(next_i>=0 && next_i<row && next_j>=0 && next_j<column) {
		if (matrix[next_i][next_j]==-1) {
			flag=true;
		}
	}
	else {
		flag=true;
	}
	return flag;
}

int main()
{
	int row, column;
	cin >> row >> column;
	int matrix[100][100];
	for(int i=0; i!=row; ++i) {
		for(int j=0; j!=column; ++j) {
			cin >> matrix[i][j];
		}
	}
	int total=0, note=0, i=0, j=0;
	int direct[4][2]={ {0,1}, {1,0}, {0,-1}, {-1,0} };
	while(total!=row*column) {
		cout << matrix[i][j] << endl;
		matrix[i][j]=-1;
		total+=1;

		if(is_border(i+direct[note][0], j+direct[note][1], row, column, matrix))
			note=(note+1)%4;
		i+=direct[note][0];
		j+=direct[note][1];
	}
	return 0;
}
