#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main()
{
	int matrix[5][5];
	int row_max[5]={0,0,0,0,0};
	for(int i=0; i!=5; ++i) {
		for(int j=0; j!=5; ++j) {
			cin >> matrix[i][j];
			if (matrix[i][j] > matrix[i][row_max[i]]) {
				row_max[i]=j;
			}
		}
	}
	bool whole=true;
	for(int row=0; row!=5; ++row) {
		int current_col=row_max[row];
		bool flag=true;
		for(int check=0; check!=5; ++check) {
			if(matrix[check][current_col] < matrix[row][current_col]) {
				flag=false;
			}
		}
		if(flag) {
			whole=false;
			cout << row+1 << " " << current_col+1 
				<< " " << matrix[row][current_col] << endl;
		}
	}
	if(whole) {
		cout << "not found" << endl;
	}
	return 0;
}
