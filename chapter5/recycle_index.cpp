#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include "split.h"
using std::cin; using std::cout;
using std::string; using std::streamsize;
using std::vector;    using std::endl;

vector<vector> recycle(vector<string> origin){
  vector<vector> box;
  box.push_back(origin);
  vector<string>::const_iterator=origin.begin();
  
}
int main(){
  vector<string> words;
  string s;
  while(getline(cin, s)){
    words=split(s);
  }

}