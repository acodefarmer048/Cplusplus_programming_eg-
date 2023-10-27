#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector;
bool is_digits(char c)
{
	bool flag=false;
	if(c>='0' && c<='9') {
		flag = true;
	}
	return flag;
}
int main()
{
	int fir_bin, sec_bin, target_bin;
	string fir_num, sec_num;
	cin >> fir_bin >> fir_num >> sec_bin >> sec_num >> target_bin;
	int left=0, right=0;
	int weight=1;
	for(string::reverse_iterator it=fir_num.rbegin();
		it!=fir_num.rend(); ++it) {
		if(is_digits(*it)) {
			left+=(*it-'0')*weight;
		}
		else {
			left+=(*it-'a'+10)*weight;
		}
		weight*=fir_bin;
	}	
	weight=1;
	for(string::reverse_iterator it=sec_num.rbegin();
		it!=sec_num.rend(); ++it) {
		if(is_digits(*it)) {
			right+=(*it-'0')*weight;
		}
		else {
			right+=(*it-'a'+10)*weight;
		}
		weight*=sec_bin;
	}	
	int result=left+right;
	vector<char> bin_result;
	while(result) {
		int tmp=result%target_bin;
		if(tmp>9) 
			bin_result.push_back(char(tmp-10+'a'));
		else
			bin_result.push_back(char(tmp+'0'));
		result/=target_bin;
	}
	for(vector<char>::reverse_iterator it=bin_result.rbegin();
		it!=bin_result.rend(); ++it) {
		cout << *it;
	}
	cout << endl;
	return 0;
}
