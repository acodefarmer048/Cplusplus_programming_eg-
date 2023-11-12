#include <iostream>
#include <set>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::set;
using std::vector;

int find_whole_seq(vector<int>& source, int n)
{
	set<int> record;
	int ans=0;
	for (vector<int>::reverse_iterator it=source.rbegin();
		it!=source.rend(); ++it) {
		record.insert(*it);
		if (record.size()==n) {
			record.clear();
			++ans;
		}
	}
	return ans+1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> melody;
	int beat;
	for (int i=0; i!=n; ++i) {
		cin >> beat;
		melody.push_back(beat);
	}
	cout << find_whole_seq(melody, m);
	return 0;
}
		
