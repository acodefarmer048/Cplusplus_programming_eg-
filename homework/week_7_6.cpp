#include <iostream>

using std::cin; using std::cout;
using std::endl;

bool is_one(char (&source)[10][10],char (&target)[10][10], int n)
{
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			if (source[i][j]!=target[j][n-1-i]) 
				 return false;
		}
	}
	return true;
}
bool is_two(char (&source)[10][10],char (&target)[10][10], int n)
{
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			if (source[i][j]!=target[n-1-j][i]) 
				 return false;
		}
	}
	return true;
}
bool is_three(char (&source)[10][10],char (&target)[10][10], int n)
{
	int center=n/2;
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			if (source[i][j]!=target[i+(center-i)*2][j+(center-j)*2]) 
				 return false;
		}
	}
	return true;
}
bool is_four(char (&source)[10][10],char (&target)[10][10], int n)
{
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			if (source[i][j]!=target[i][j]) 
				 return false;
		}
	}
	return true;
}

int main()
{
	char source[10][10], target[10][10];
	int n;
	cin >> n;
	
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			cin >> source[i][j];
		}
	}
	for (int i=0; i!=n; ++i) {
		for (int j=0; j!=n; ++j) {
			cin >> target[i][j];
		}
	}
	if (is_one(source, target, n)) {
		cout << 1;
		return 0;
	}
	if (is_two(source, target, n)) {
		cout << 2;
		return 0;
	}
	if (is_three(source, target, n)) {
		cout << 3;
		return 0;
	}
	if (is_four(source, target, n)) {
		cout << 4;
		return 0;
	}
	cout << 5;
	return 0;
}
