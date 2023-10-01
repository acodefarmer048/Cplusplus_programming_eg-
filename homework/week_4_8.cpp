#include <iostream>
#include <numeric>
#include <string>

using std::cin; using std::cout;
using std::accumulate; using std::endl;
using std::string; 

bool is_digits(const char& c)
{
	if (c>=48 && c<=57) 
		return true;
	else
		return false;
}
bool is_lowercase(const char& c)
{
	if (c>=97 && c<=122) 
		return true;
	else
		return false;
}
bool is_uppercase(const char& c)
{
	if (c>=65 && c<=90) 
		return true;
	else
		return false;
}
int dimension(string& codes)
{
	int species[4]={0,0,0,0};
	for(string::const_iterator it=codes.begin();
		it!=codes.end(); ++it) {

		if(is_digits(*it))
			species[0]=1;
		else if(is_lowercase(*it))
			species[1]=1;
		else if(is_uppercase(*it))
			species[2]=1;
		else
			species[3]=1;
	}
	int sum = accumulate(species, species+4, 0);
	return sum;
}

	
		
int determine(string& codes)
{
	
	int kinds=dimension(codes);
	if (codes.size() < 6) {
		cout << "Not safe" << endl;
	}
	else if(kinds==1) {
		cout << "Not safe" << endl;
	}
	else if(kinds==2) {
		cout << "Medium safe" << endl;
	}
	else {
		cout << "Safe" << endl;
	}

	return 0;


}
int main()
{
	int n;
	cin >> n;

	string codes;
	for (int i=0; i<n; ++i) {
		cin >> codes;
		determine(codes);
	}
		
	return 0;
}

