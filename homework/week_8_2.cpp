#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::sort;

struct activity {
	int beg;
	int end;
};

bool compare(activity& left, activity& right)
{
	return left.end < right.end;
}

int main()
{
	int n;
	cin >> n;
	activity perform;
	vector<activity> lists;
	for (int i=0; i!=n; i++) {
		cin >> perform.beg >> perform.end;
		lists.push_back(perform);
	}
	sort(lists.begin(), lists.end(), compare);
	int count=0, max_count=-1;
	vector<activity>::iterator beg=lists.begin(), current, prev;
	while (beg!= lists.end()) {
		count=1;
		current=beg+1;
		prev=beg;
		while (current!=lists.end()) {
			if ( (*prev).end <= (*current).beg) {
				++count;
				prev=current;
			}
			++current;
		}
		if (max_count==-1 || count > max_count)
			max_count=count;
		++beg;
	}
	cout << max_count;
	return 0;
}
