#include <iostream>

using std::cin; using std::cout;
using std::endl;

int main()
{
	int rows, columns;
	bool flag;
	char pad;
	while (cin >> rows && rows!= 0) {
		cin >> columns >> pad >> flag;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				if (i==0||j==0||i==rows-1||j==columns-1)
					cout << pad;
				else if (flag)
					cout << pad;
				else   cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
