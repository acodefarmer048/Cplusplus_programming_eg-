#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector;

void print(vector<string>& sen, int beg, int end)
{
	cout << sen[beg];
	for (int i=beg+1; i!=end; ++i) {
		cout << " " << sen[i];
	}
	cout << endl;
}

int main()
{
	string word;
	vector<string> sen;
	int n;
	cin >> n;
	for (int i=0; i!=n; ++i) {
		cin >> word;
		sen.push_back(word);
	}
	int length=0, beg=0;
	for (int i=0; i!=n; ++i) {
		if (length+sen[i].size() > 80) {
			print(sen, beg, i);
			length=0;
			beg=i;
		}
		if (i==n-1) {
			print(sen, beg, i+1);
		}
		length+=sen[i].size()+1;

	}
	return 0;
}
