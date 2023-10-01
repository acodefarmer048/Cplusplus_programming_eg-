#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::make_heap; using std::pop_heap;
using std::push_heap; using std::string;
using std::greater;

int main()
{
	int n;
	cin >> n;
	vector<int> heap;

	int ori;
	for(int i=0; i<n; ++i) {
		cin >> ori;
		heap.push_back(ori);
	}
	make_heap(heap.begin(), heap.end(),greater<int>() );

	int commands;
	cin >> commands;
	string order;
	for (int i=0; i<commands; ++i) {
		cin >> order;
		if (order=="EXTRACT-MIN") {
			if (heap.empty()) {
				cout << "NULL" << endl;
			}
			else {
				pop_heap(heap.begin(), heap.end(),greater<int>() );
				int tmp=heap.back();
				cout << tmp << endl;
				heap.pop_back();
			}
		}
		else {
			int num;
			cin >> num;

			heap.push_back(num);
			push_heap(heap.begin(), heap.end(),greater<int>() );
		}
	}

	return 0;
}
			
			
		
