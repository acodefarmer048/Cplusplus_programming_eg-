#include <iostream>
#include <list>

using std::cin; using std::cout;
using std::endl; using std::list;
using std::istream;

class Dots {
private:
	int x, y;
public:
	bool is_included(Dots another) {
		if (x<=another.x && y<=another.y) 
			return true;
		else
			return false;
	}
	bool is_related(Dots another) {
		if ((*this).is_included(another) || another.is_included(*this))
			return true;
		else
			return false;
	}
	istream& read_dot(istream& cin) {
		cin >> x >> y;
		return cin;
	}
	int show_x() {
		return (*this).x;
	}
	void print() {
		cout << "(" << x << "," << y << ")" ;
	}
		
};
bool compare(Dots left, Dots right) {
	return left.show_x() < right.show_x();
}

int main()
{
	int n;
	cin >> n;
	Dots dot;
	list<Dots> spots;
	for(int i=0; i<n; ++i) {
		dot.read_dot(cin);
		spots.push_back(dot);
	}

	
	for(list<Dots>::iterator i_it=spots.begin();
		i_it != spots.end(); ++i_it) {
		list<Dots>::iterator j_it=i_it;
		while(j_it != spots.end()) {
			if(j_it == i_it)
				++j_it;
			else if ((*i_it).is_included(*j_it)) {
				i_it=spots.erase(i_it);
				j_it=i_it;
			}
			else if ((*j_it).is_included(*i_it)) {
				j_it=spots.erase(j_it);
			}
			else {
				++j_it;
			}
		}
	}
	spots.sort(compare);
	
	for(list<Dots>::iterator it=spots.begin();
		it != spots.end(); ++it) {
		if (it==spots.begin())
			(*it).print();
		else {
			cout << "," ;
			(*it).print();
		}
	}
	return 0;
}
			
			
				

