#include <iostream>
#include <vector>
#include <algorithm>

using  std::cin; using std::cout;
using std::endl; using std::vector;
using std::sort; using std::istream;

class glass_garden {
public:
	istream& read_basic(istream& cin)
	{
		cin >> label >> pre_num >> aft_num;
		return cin;
	}

	double calculate_rate()
	{
		multiply_rate=aft_num*1.0/pre_num;
		return multiply_rate;
	}
	void identification(char c)
	{
		species=c;
	}
	double observe() const  //only this can makre sure that a const_iterator can call this function through *
	{
		return multiply_rate;
	}
	void print() const
	{
		cout << label << endl;
	}
private:
	int label;
	int pre_num;
	int aft_num;
	char species;
	double multiply_rate;
};

bool compare(glass_garden left, glass_garden right)
{
	return left.observe() < right.observe();
}
vector<glass_garden>::const_iterator find_gap(vector<glass_garden>& vc)
{
	sort(vc.begin(), vc.end(), compare);
	double diff=0;
	vector<glass_garden>::const_iterator note=vc.begin();
	for(vector<glass_garden>::const_iterator it=vc.begin();
		it!=vc.end()-1; ++it) {
		double tmp=(*(it+1)).observe()-(*it).observe();
		if (tmp>diff) {
			diff=tmp;
			note=it+1;
		}
	}
	return note;
}

int main()
{
	int n;
	cin >> n;
	vector<glass_garden> bacteria;
	glass_garden germ;
	for (int i=0; i<n; ++i) {
		germ.read_basic(cin);
		germ.calculate_rate();
		bacteria.push_back(germ);
	}
	
	vector<glass_garden>::const_iterator note=find_gap(bacteria);
	cout << bacteria.end()-note << endl;
	for(vector<glass_garden>::const_iterator it=note;
		it!=bacteria.end(); ++it) {
		(*it).print();
	}
	cout << note-bacteria.begin() << endl;
	for(vector<glass_garden>::const_iterator it=bacteria.begin();
		it!=note; ++it) {
		(*it).print();
	}
	return 0;
}
