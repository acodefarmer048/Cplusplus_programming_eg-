#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "final_grade.h"
#include "final_stu.h"

using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;
int main(){
    vector<final_stu> students;
    final_stu record;
    string::size_type maxlen = 0;
    while(read(cin,record)){
        maxlen=max(maxlen, record.name.size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(),compare);
    for(vector<final_stu>::const_iterator iter=students.begin();
        iter!=students.end();++iter){
            streamsize prec=cout.precision();
            cout << iter->name
                 << string(maxlen+1-(*iter).name.size(),' ')
                 << setprecision(3)
                 << iter->final_grade
                 << setprecision(prec)
                 << endl;
        }

    system("pause");
    return 0;
}