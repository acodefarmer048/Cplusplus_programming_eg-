#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::vector;

bool read_book(vector<int>& root, int page)
{
	if (root[page]!=-1 && root[page]!=page) {
		read_book(root, root[page]);
		root[page]=-1;
	}
	else if (root[page]!=-1) {
		root[page]=-1;
	}
	else {
		return 0;
	}

	return 1;
}
		
int main()
{
	int pages;
	cin >> pages;
	vector<int> root;
	int tmp;
	for (int i=0; i< pages; ++i) {
		cin >> tmp;
		root.push_back(tmp-1);
	}

	int days=0;
	for (int i=0; i<pages; ++i) {
		if (read_book(root, i)) {
			days+=1;
		}
	}

	cout << days;

	return 0;
}
		
