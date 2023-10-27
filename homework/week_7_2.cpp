#include <iostream>
#include <string>

using namespace std;

bool is_leap(int year)
{
	if ((year%4==0 && year%100!=0) || (year%400==0)) {
		return true;
	}
	return false;
}

int max_days(int year, int month)
{
	int leap_year[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int common_year[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (is_leap(year)) {
		return leap_year[month];
	}
	else {
		return common_year[month];
	}
}
	
int main() {
    int n;
    cin >> n;

    string s;
    int year = 2021, month = 1, day = 3;
    while (year <= 9999) {
        string yearStr = to_string(year);
        string monthStr = to_string(month);
        string dayStr = to_string(day);
        if (monthStr.length() == 1) {
            monthStr = "0" + monthStr;
        }
        if (dayStr.length() == 1) {
            dayStr = "0" + dayStr;
        }
        s += yearStr + monthStr + dayStr;

        day++;
        if (day > max_days(year, month)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        size_t pos = s.find(to_string(num));
        if (pos != string::npos) {
            cout << pos + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
		
	
	
