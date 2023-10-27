#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::getline; using std::stringstream;
using std::string; using std::max;
using std::max_element; using std::min_element;

bool between(int begin,int end, int i)
{
	if (end > i && i >= begin) 
		return true;
	else
		return false;
}

int read(vector<int>& enter, vector<int>& leave)
{
	int time;
	char delimiter;
	string table;
	stringstream sstream;
	getline(cin, table);
	cout << "enter: " << table << endl;
	sstream << table;
	while(true) {
		sstream >> time;
		enter.push_back(time);
		if (sstream.rdbuf()->in_avail() != 0)
			sstream >> delimiter;
		else
			break;
	}
	
	getline(cin, table);
	cout << "leave: " << table << endl;
	sstream.clear();
	sstream << table;
	while(true) {
		sstream >> time;
		leave.push_back(time);
		if (sstream.rdbuf()->in_avail() != 0)
			sstream >> delimiter;
		else
			break;
	}
	return enter.size();
}
int main()
{
	vector<int> enter, leave;
	cout << read(enter, leave) << " ";
	int max_num=0;
	int inf=*min_element(enter.begin(), enter.end());
	int sup=*max_element(leave.begin(), leave.end());
	for(int i=inf; i!=sup; ++i) {
		int count=0;
		for(int j=0; j!=enter.size(); ++j) {
			if (between(enter[j],leave[j], i)) {
				++count;
			}
		}
		max_num=max(count, max_num);
	}
	cout << max_num << endl;

	for(int j=0; j!=enter.size(); ++j) {
		cout << enter[j]<< " ";
	}
	cout << endl;
	for(int j=0; j!=enter.size(); ++j) {
		cout << leave[j]<< " ";
	}
	return 0;
}
