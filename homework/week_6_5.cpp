#include <iostream>
#include <sstream>
#include <string>
#include <map>

using std::cin; using std::cout;
using std::endl; using std::stringstream;
using std::string; using std::map;
using std::getline;

//--------------------integration-struct-for-date-related-statistics-------------
struct Date {
	int year;
	int month;
	int day;
};
//---------------------------auxiliary-function-of-calculate-days----------------
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
		
//---------------------------body-of-calculate-days------------------------------
int calculate_days(int end_year, int end_month, int end_day)
{
	int start_year=1900,start_month=1,start_day=1;
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
	return total;
}

//---------------auxiliary-function-for-date_string-dealing----------------------
//beg must be the iterator of str
string::iterator find_delimiter(string& str, string::iterator beg) 
{
	string::iterator it=beg;
	while(*it!='-' && it!=str.end()) {
		++it;
	}
	return it;
}

int translate(string& smonth)
{
	map<string, int> trans_str={{"Jan", 1},{"Feb", 2},{"Mar", 3},
			{"Apr", 4},{"May", 5},{"Jun", 6},{"Jul", 7},{"Aug", 8},
			{"Sep", 9},{"Oct", 10},{"Nov", 11},{"Dec", 12} };
	return trans_str[smonth];
}		
string translate(int ofweek)
{
	map<int, string> trans_int = { {7,"Sun"},{6,"Sat"},{5,"Fri"},
			{4,"Thu"},{3,"Wed"},{2,"Tue"},{1,"Mon"} };
	return trans_int[ofweek];
}		

Date parse_date(string& str)
{
	int year, day;
	string smonth;
	string::iterator it=str.begin(), delimiter=str.end();
	stringstream ss;
	while(it!=str.end()) {
		if(delimiter!=str.end()) {
		//if true means that a delimiter exists, so it should move one step forward to avoid error
			++it;
		}
		delimiter=find_delimiter(str, it);
		string tmp(it, delimiter);
		ss << tmp;
		switch (tmp.size())
		{
			case 4: ss >> year; break;
			case 3: ss >> smonth; break;
			case 2: ss >> day; break;
			default: break;
		}
		it=delimiter;
		ss.clear();
	}
	int month=translate(smonth);
	Date date;
	date.year=year;
	date.month=month;
	date.day=day;
	return date;
}
	
string which_day(int days_gap)
{
	int mol=days_gap%7;
	return translate(mol+1);
}
//---------------------------body-of-main-function-------------------------------
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string sdate;
	for(int i=0; i!=n; ++i) {
		getline(cin, sdate);
		Date date=parse_date(sdate);
		int gap = calculate_days(date.year, date.month, date.day);
		cout << which_day(gap) << '.' << endl;
	}
	return 0;
}
