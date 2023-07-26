#include "word.h"
#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
using  std::streamsize; using std::string;
using std::vector;  using std::istream;

vector<string> word(istream& in){
    vector<string> voca;
    string w;
    while(in>>w)
        voca.push_back(w);
    return voca;
}