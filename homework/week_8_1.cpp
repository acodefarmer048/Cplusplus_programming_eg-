#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout;
using std::endl; using std::vector;
using std::string; using std::getline;

struct Word {
	string word;
	int freq;
};

bool is_letters(char c)
{
	if ( (c >='a' && c <='z') || (c >='A' && c <='Z') || (c == '\'') )
		return true;
	return false;
}
string::iterator find_letter(string& str, string::iterator beg)
{
	string::iterator it=beg;
	while(!is_letters(*it) && it!=str.end())
		++it;
	return it;
}
string::iterator find_delimiter(string& str, string::iterator beg)
{
	string::iterator it=beg;
	while(is_letters(*it) && it!=str.end())
		++it;
	return it;
}
bool strcmp(string& left, string& right)
{
	if (left.size()!=right.size())
		return false;
	string::iterator l_it=left.begin(), r_it=right.begin();
	while (*l_it == *r_it && l_it!=left.end()) {
		++l_it;
		++r_it;
	}
	if (l_it==left.end())
		return true;
	return false;
}
vector<Word>::iterator is_duplicated(vector<Word>& dict, string str)
{
	for(vector<Word>::iterator it=dict.begin();
		it!=dict.end(); ++it) {
		if (strcmp((*it).word, str))
			return it;
	}
	return dict.end();
}


int main()
{
	string sentence;
	getline(cin, sentence);
	vector<Word> dict;
	string::iterator beg=sentence.begin(), end;
	while (beg!=sentence.end()) {
		beg = find_letter(sentence, beg);
		end = find_delimiter(sentence, beg);
		if (beg != sentence.end()) {
			vector<Word>::iterator occur=is_duplicated(dict,
				sentence.substr(beg-sentence.begin(), end-beg));
			if (occur != dict.end()) {
				(*occur).freq++;
			}
			else {
				Word emerged={ sentence.substr(beg-sentence.begin(), end-beg), 1};
				dict.push_back(emerged);
			}
		}
		beg=end;
	}
	for( vector<Word>::iterator it=dict.begin();
		it!=dict.end(); ++it) {
		cout << (*it).word << " " << (*it).freq <<endl;
	}

	return 0;
}
			

