#include <iostream>
#include <sstream>
#include <string>
#include <map>

using std::cin; using std::cout;
using std::endl; using std::stringstream;
using std::string; using std::map;
using std::getline;

//---------------------------auxiliary-function-of-calculate-days----------------
bool is_leap_year(int year)
{
	if ((year % 4==0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
int month_accumu(int start, int end, bool is_lap)
{
	int commom_year[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int lap_year[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int total=0;
	if(is_lap) {
		for(int i=start; i!=end; ++i) {
			total+=lap_year[i-1];
		}
	}
	else {
		for(int i=start; i!=end; ++i) {
			total+=commom_year[i-1];
		}
	}
	return total;
}
		
		
//---------------------------body-of-main-function-------------------------------
int main()
{
	int n;
	cin >> n;
	int year, start_month, end_month;
	for (int i=0; i!=n; ++i ) {
		int first, second;
		cin >> year >> first >> second;
		if (first > second) {
			start_month=second;
			end_month=first;
		}
		else {
			start_month=first;
			end_month=second;
		}
		int days=month_accumu(start_month, end_month, is_leap_year(year));
		if (days%7==0) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}


