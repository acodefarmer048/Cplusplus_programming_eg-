#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::map;
using std::vector; using std::sort;
using std::unique;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	map<int, vector<int> > fans;
	for (int i=0; i!=n; ++i) {
		int poster, cited, k;
		cin >> poster >> k;
		for (int j=0; j!=k; j++) {
			cin >> cited;
			fans[cited].push_back(poster);
		}
	}
	int popular;
	vector<int> citers;
	for (map<int, vector<int> >::iterator it=fans.begin();
		it != fans.end(); ++it) {
		if (it->second.size() > citers.size() ) {
			citers=it->second;
			popular=it->first;
		}
	}
	cout << popular << endl;
	sort(citers.begin(), citers.end());
	citers.erase(unique(citers.begin(), citers.end()), citers.end());
	cout << citers[0];
	for (vector<int>::iterator it=citers.begin()+1;
		it!=citers.end(); ++it) {
		cout << " " << *it ;
	}

	return 0;
}
