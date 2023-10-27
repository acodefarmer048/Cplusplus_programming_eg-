#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::string;
using std::vector; using std::istream;

class big_num {
private:
	vector<int> abs;
	int sign;
	big_num add_absolute(big_num& );
	big_num substract_absolute(big_num& );
public:
	big_num():abs(), sign(1) {}
	big_num(const vector<int> array, int given): abs(array), sign(given) {}
	big_num(const big_num& tmp): abs(tmp.abs), sign(tmp.sign) {}
	explicit big_num(istream& cin): abs(), sign(1) {
		(*this).read(cin);
	}	
	big_num& operator=(const big_num right) {
		(*this).sign=right.sign;
		(*this).abs=right.abs;
		return *this;
	}
	~big_num() {}

	istream& read(istream& cin)
	{
		string original;
		int begin=-1;
		cin >> original;
		if (original[0]=='-') {
			sign=-1;
			++begin;
		}
		else if(original[0]=='+') {
			sign=1;
			++begin;
		}
		else {
			sign=1;
		}
		int current=original.size()-1;
		while(begin!=current) {
			abs.push_back(int(original[current])-48);//small end
			--current;
		}
		return cin;
	}
	int show() 
	{
		return sign;
	}
	big_num opposite()
	{
		big_num changed((*this).abs, -(*this).sign);
		return changed;
	}

	void print()
	{
		if(sign==-1 && !(abs.size()==1 && abs[0]==0)) {
			cout << '-';
		}
		for(vector<int>::reverse_iterator it=abs.rbegin();
			it != abs.rend(); ++it) {
			cout << *it;
		}
		cout << endl;
	}
	big_num substract(big_num& second)
	{
		big_num result;
		if((*this).show()==second.show()) {
			result=(*this).substract_absolute(second);
		}
		else {
			big_num tmp=second.opposite();
			result=(*this).add_absolute(tmp);
		}
		return result;
	}
};


//----------------------------------------------------------member-function-implementation-----------------
big_num big_num::substract_absolute(big_num& subtrahend)
{
	vector<int>::const_iterator left=(*this).abs.begin();
	vector<int>::const_iterator right=subtrahend.abs.begin();
	vector<int> result;
	int borrow=0;
	while(right!=subtrahend.abs.end()) {
		if (left!=(*this).abs.end()) {
			if(*left<borrow+*right) {
				result.push_back(10+*left-borrow-*right);
				borrow=1;
			}
			else {
				result.push_back(*left-borrow-*right);
				borrow=0;
			}
		}
		else {
			big_num done = subtrahend.substract_absolute(*this);
			return done.opposite();

		}
		++left;
		++right;
	}
	while(borrow!=0) {
		if (left!=(*this).abs.end()) {
			if(*left<borrow) {
				result.push_back(10+*left-borrow);
				borrow=1;
			}
			else {
				result.push_back(*left-borrow);
				borrow=0;
			}
		}
		else {
			big_num done = subtrahend.substract_absolute(*this);
			return done.opposite();
		}
		++left;
	}
	while(left!=(*this).abs.end()) {
		result.push_back(*left);
		++left;
	}
	int check=result.size()-1;
	while (check!=0) {
		if(result[check]==0) {
			result.pop_back();
		}
		else {
			break;
		}
		--check;
	}
	big_num done(result,(*this).sign);

	return done;
}
big_num big_num::add_absolute(big_num& addent)
{
	vector<int>::const_iterator left=(*this).abs.begin();
	vector<int>::const_iterator right=addent.abs.begin();
	vector<int> result;
	int carry=0;
	while(left!=(*this).abs.end() && right!=addent.abs.end()) {
		if(*left+*right+carry>9) {
			result.push_back(*left+*right+carry-10);
			carry=1;
		}
		else {
			result.push_back(*left+*right+carry);
			carry=0;
		}
		++left;
		++right;
	}

	while (left!=(*this).abs.end())	{
		if(*left+carry>9) {
			result.push_back(*left+carry-10);
			carry=1;
		}
		else {
			result.push_back(*left+carry);
			carry=0;
		}
		++left;
	}
			
	while (right!=addent.abs.end()) {
		if(*right+carry>9) {
			result.push_back(*right+carry-10);
			carry=1;
		}
		else {
			result.push_back(*right+carry);
			carry=0;
		}
		++right;
	}
	if(carry!=0) {
		result.push_back(carry);
		carry=0;
	}
	big_num done(result,(*this).sign);
	return done;
}
//-------------------------------------------------------main-function--------------------------



		
int main()
{
	int n;
	cin >> n;
	for(int i=0; i!=n; ++i) {
		big_num first(cin);
		big_num second(cin);
		big_num result=first.substract(second);

		result.print();
	}
	return 0;
}

