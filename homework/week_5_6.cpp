#include <iostream>

using std::cin; using std::cout;
using std::endl;

bool is_lap_year(int year)
{
	if ((year % 4==0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
int year_accumu(int start, int end)
{
	int total=0;
	for(int i=start; i!=end; ++i) {
		if(is_lap_year(i)) {
			total+=366;
		}
		else {
			total+=365;
		}
	}
	return total;
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
		
int day_accumu(int month, int day, bool is_lap)
{
	int commom_year[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int lap_year[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int total=0;
	if(is_lap) {
		total+=lap_year[month-1]-day;
	}
	else {
		total+=commom_year[month-1]-day;
	}
	return total;
}
		
int main()
{
	int end_year, end_month, end_day, start_year, start_month, start_day;
	cin >> start_year >> start_month >> start_day >> end_year >> end_month >> end_day;
	int total=0;
	if (start_year==end_year) {
		if(start_month==end_month) {
			total+=end_day-start_day;
		}
		else {
			total+=day_accumu(start_month, start_day, is_lap_year(start_year));
			total+=end_day;
			if(start_month!=end_month-1) 
				total+=month_accumu(start_month+1, end_month, is_lap_year(start_year));
		}
	}
	else {
		total+=day_accumu(start_month, start_day, is_lap_year(start_year));
		total+=month_accumu(start_month+1, 13, is_lap_year(start_year));
		total+=month_accumu(1, end_month, is_lap_year(end_year));
		total+=end_day;
		if(start_year!=end_year-1) 
			total+=year_accumu(start_year+1, end_year);
	}
	cout << total << endl;
	return 0;
}

