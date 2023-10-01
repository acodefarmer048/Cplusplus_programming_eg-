#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl;  using std::vector;

int go_down(int note, vector<int>& root)
{
	if (root[note-1] != note) {
		root[note-1]=go_down(root[note-1], root);
	}
	return root[note-1];
}

bool set_check(int one, int two, vector<int>& root)
{
	return go_down(one, root)==go_down(two, root);
}


int main()
{
	int patients, commands;
	cin >> patients >> commands;
	
	vector<int> root(patients);
	for (int i=0; i!=patients; ++i) {
		root[i]=i+1;
	}//initialize

	for (int i=0; i!=commands; ++i) {
		char order;
		int num_1, num_2;
		cin >> order >> num_1 >> num_2;

		if (order=='M') {
			go_down(num_1, root);
			root[root[num_1-1]-1]=go_down(num_2, root);
		}

		else {
			if (set_check(num_1, num_2, root)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}

	return 0;
}

