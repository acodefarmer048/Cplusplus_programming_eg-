#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include "word.h"

 using std::cin; using std::cout;
 using std::string; using std::streamsize;
 using std::ios;  using std::endl;
 using std::vector;
 
 int main(){
    vector<string> voca=word(cin);
    vector<string>::size_type size=voca.size();
    vector<string>::iterator iter=voca.begin();
    while(iter!=voca.end()){
      vector<string>::iterator vice_iter=iter+1;
      int repet=1;
      while(vice_iter!=voca.end()){
            if(*vice_iter==*iter){
              ++repet;
              vice_iter=voca.erase(vice_iter);//function erase only support operations based on pointer rather than index;
            }else{
              ++vice_iter;
            }
      }
      cout << *iter << " repetition: " << repet << endl;
      ++iter;
    }
    system("pause");
    return 0;
 }