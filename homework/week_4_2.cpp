#include <iostream>
#include <cmath>

using std::cin; using std::cout;
using std::endl; using std::abs;

int main()
{
	//get in the matrix
	int rows, columns, tar_r, tar_c;
	cin >> rows >> columns;
	int matrix[rows][columns];
	for (int i=0; i< rows; ++i) {
		for (int j=0; j< columns; ++j) {
			cin >> matrix[i][j];
		}
	}
	//target matrix
	cin >> tar_r >> tar_c;
	int target[tar_r][tar_c];
	for (int i=0; i< tar_r; ++i) {
		for (int j=0; j< tar_c; ++j) {
			cin >> target[i][j];
		}
	}

	int result_coor[2];//record the up_left coordinate;
	int previous=2147483647;

	for (int i_plus=0; i_plus+tar_r<= rows; ++i_plus) {
		for (int j_plus=0; j_plus+tar_c<= columns; ++j_plus) {
			int sum=0;
			for (int i=0; i< tar_r; ++i) {
				for (int j=0; j< tar_c; ++j) {
					sum+=abs(matrix[i_plus+i][j_plus+j]-target[i][j]);
				}
			}
			if (sum < previous) {
				result_coor[0]=i_plus;
				result_coor[1]=j_plus;

				previous=sum;
			}
		}
	}

	for (int i=0; i< tar_r; ++i) {
		for (int j=0; j< tar_c; ++j) {
			cout << matrix[result_coor[0]+i][result_coor[1]+j] << " ";
		}
		cout << endl;
	}
	return 0;
}


		
