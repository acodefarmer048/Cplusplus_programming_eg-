#include <iostream>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::vector;

struct Infected_Dorm {
	int row;
	int column;
};

bool is_valid(int row, int column, int n)
{
	if (row >=0 && row <n && column >=0 && column <n)
		return true;
	else 
		return false;
}

int update(char (&dorms)[100][100], vector<Infected_Dorm>& monitored, int n)
{
	Infected_Dorm infect;
	vector<Infected_Dorm> todays;
	int direct[4][2]={ {1,0}, {-1,0}, {0,-1}, {0,1} };
	int neighbor_row, neighbor_column;
	for (vector<Infected_Dorm>::iterator it=monitored.begin();
		it != monitored.end(); ++it) {
		for (int i=0; i!=4; ++i) {
			neighbor_row=(*it).row+direct[i][0];
			neighbor_column=(*it).column+direct[i][1];
			if (is_valid(neighbor_row, neighbor_column, n)) {
				if (dorms[neighbor_row][neighbor_column]=='.') {
					infect.row=neighbor_row;
					infect.column=neighbor_column;
					todays.push_back(infect);
					dorms[neighbor_row][neighbor_column]='@';
					
				}
			}
		}
	}
	monitored=todays;
	return todays.size();
}
		
int main()
{
	int n,m, total=0;
	char dorms[100][100];
	vector<Infected_Dorm> monitored;
	cin >> n;
	
	Infected_Dorm patient;
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			cin >> dorms[i][j];
			if (dorms[i][j]=='@') {
				patient.row=i; 
				patient.column=j;
				monitored.push_back(patient);
				++total;
			}
		}
	}
	cin >> m;
	int days=1;
	while (days < m) {
		total+=update(dorms, monitored, n);
		++days;	
	}
	cout << total;
	return 0;
}
	
