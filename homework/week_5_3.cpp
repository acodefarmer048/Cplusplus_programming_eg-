#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::vector;

int main()
{
	int pupil;
	cin >> pupil;
	for(int i=0; i<pupil; ++i) {
		int waiting=0, loops=60, mistakes;
		cin >> mistakes;
		int current;
		vector<int> suspension;
		for(int j=0; j<mistakes; ++j) {
			cin >> current;
			suspension.push_back(current);
		}
		for(vector<int>::const_iterator it=suspension.begin();
			it!=suspension.end(); ++it) {

			if(waiting+*it>=60) {
				break;
			}
			else if(*it+waiting+3>=60) {
				waiting=60-*it;
				break;
			}
			else {
				waiting+=3;
			}
		}
		loops-=waiting;
		cout << "waiting :" << waiting << endl;
		cout <<"result: " << loops << endl;
	}
	return 0;
}
