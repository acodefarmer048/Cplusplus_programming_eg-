#include <iostream>
#include <cctype>
#include <vector>
#include <ios>
#include <string>
#include <algorithm>
using std::cin; using std::cout;
using std::string; using std::search;
using std::endl; using std::vector;
using std::find_if; using std::find;
using std::isalnum;
vector<string> find_urls(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	//look through the entire input
	while ( b!= e) {
		//look for one or more letters followed by ://
		b = url_beg(b,e);
		//if we found it 
		if (b != e){
			//get the rest of the url
			iter after = url_end(b,e);
			//remember the url
			ret.push_back(string(b,after));
			//advance b and check for more urls on this line
			b = after;
		}
	}
	return ret;
}
string::const_iterator
url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b,e,not_url_char);
}
bool not_url_char(char c)
{
	//characters, in addition to alphanumerics, that can appear in a url
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	//see whether c can appear in a url and return the negative
	return !(isalnum(c) ||
		find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}
string::const_iterator
url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep="://";
	typedef string::const_iterator iter;
	// i marks where the separator was found
	iter i=b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
		if (i != b && i + sep.size() != e){
			//beg marks the begining of the protocol-name
			iter beg = i;
			while (beg != i && isalpha(beg[-1]))
				--beg;
			// is there at least one appropriate character before and after the seperator?
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}
		i+= sep.size();
	}
	return e;
}
